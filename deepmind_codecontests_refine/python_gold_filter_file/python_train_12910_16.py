n, k = map(int, input().split())
ww = [int(input()) for _ in range(n)]
def chk(p):
    c = 1
    s = 0
    for w in ww:
        if w > p:
            return False
        if s + w <= p:
            s += w
        else:
            c += 1
            s = w
        if c > k:
            return False
    return True
def search(l, r):
    if r - l < 10:
        for i in range(l, r):
            if chk(i):
                return i
    m = (l + r) // 2
    if chk(m):
        return search(l, m + 1)
    else:
        return search(m, r)
print(search(0, 2 ** 30))