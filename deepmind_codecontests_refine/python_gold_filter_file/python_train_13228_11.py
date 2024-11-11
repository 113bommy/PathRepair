n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [int(input()) for _ in range(m)]
for i in a:
    c = 0
    for j, k in zip(i, b):
        c += j * k
    print(c)
