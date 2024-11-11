def combinations(N):
    comb = [[0] * (N + 1) for _ in range(N + 1)]
    comb[0][0] = 1
    for i in range(1, N + 1):
        for j in range(i + 1):
            comb[i][j] += comb[i - 1][j]
            if j > 0:
                comb[i][j] += comb[i - 1][j - 1]
    return comb


nCk = combinations(60)

N, A, B, *V = map(int, open(0).read().split())

V.sort(reverse=True)

num = V.count(V[A - 1])

ans = 0
if V[0] == V[A - 1]:
    ans = sum(nCk[num][A:B + 1])
else:
    a = V[:A].count(V[A - 1])
    ans = nCk[num][a]

ave = sum(V[:A]) / A

print("{:.9f}".format(ave))
print(ans)
