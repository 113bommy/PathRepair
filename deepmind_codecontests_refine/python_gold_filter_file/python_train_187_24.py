n = int(input())
F = []
for i in range(n):
    F.append(input().replace(" ", ""))
P = []
for i in range(n):
    P.append(list(map(int, input().split())))

ans = -1e10
for i in range(1, 2**10):
    s = 0
    for j in range(n):
        tmp = int(F[j], 2)
        tmp = i & tmp
        c = bin(tmp).count("1")
        s += P[j][c]
    if s > ans:
        ans = s
print(ans)
