t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    f = [0 for _ in range(1, n + 1)]
    for i in range(m):
        a, b, c = map(int, input().split())
        f[b-1] = 1
    d = 0
    for i in range(len(f)):
        if f[i] == 0:
            d = i
            break
    for i in range(1, n + 1):
        if i != d + 1:
            print(i, d + 1)
