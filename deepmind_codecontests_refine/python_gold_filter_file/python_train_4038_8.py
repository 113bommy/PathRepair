n, m, x = map(int, input().split())
bk = [list(map(int, input().split())) for _ in range(n)]
pr = 10 ** 7
for i in range(2 ** n):
    ef = [0] * (m + 1)
    for j in range(n):
        if i >> j & 1:
            ef = [p + q for (p, q) in zip(ef, bk[j])]
    for k in range(1, m + 1):
        if ef[k] < x:
            break
        if k == m:
            pr = min(pr, ef[0])
print(pr if pr != 10 ** 7 else -1)