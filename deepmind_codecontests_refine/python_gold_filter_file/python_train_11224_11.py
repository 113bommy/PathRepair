def solve(aaa):
    l = 1
    r = 200000
    while l < r:
        m = (l + r) // 2
        if check(m, aaa):
            r = m
        else:
            l = m + 1
    return r


def check(d, aaa):
    if d == 1:
        return all(a1 < a2 for a1, a2 in zip(aaa, aaa[1:]))
    l = 0
    word = [[0, 0]]
    for a in aaa:
        if l >= a:
            if not carry(d, word, a):
                return False
        l = a
    return True


def carry(d, word, i):
    while word[-1][0] > i:
        word.pop()
    while word[-1] == [i, d]:
        word.pop()
        i -= 1
    if i == 0:
        return False
    if word[-1][0] == i:
        word[-1][1] += 1
    else:
        word.append([i, 2])
    return True


n = int(input())
aaa = list(map(int, input().split()))
print(solve(aaa))
