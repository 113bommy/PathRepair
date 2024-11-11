def play(a, lst):
    b, m = sorted(lst), a // 2
    if a == 1:
        return b[0]
    elif a % 2 == 0:
        return b[m - 1]
    return b[m]


n = int(input())
z = [int(i) for i in input().split()]
print(play(n, z))
