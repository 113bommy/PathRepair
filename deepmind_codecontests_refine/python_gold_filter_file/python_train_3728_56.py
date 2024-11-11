X, Y, Z, K = map(int, input().split())
A, B, C = [sorted(list(map(int, input().split())))[:: -1][: K] for _ in range(3)]
D = []
for ai in A:
    for bi in B:
        D.append(ai + bi)

D = sorted(D)[:: -1][: K]

res = []
for di in D:
    for ci in C:
        res.append(di + ci)

res = sorted(res)[:: -1][: K]

for ans in res:
    print(ans)
