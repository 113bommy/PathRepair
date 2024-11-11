
N, K = map(int, input().split())

MOD = 10 ** 9 + 7
ans = 0
ctr = [0] * (K + 1)

for x in reversed(range(1, K + 1)):
    ctr[x] = pow(K // x, N, MOD)
    for y in range(2 * x, K + 1, x):
        ctr[x] -= ctr[y]

ans = 0
for n in range(1, K + 1):
    ans += n * ctr[n]
    ans %= MOD

print(ans)
