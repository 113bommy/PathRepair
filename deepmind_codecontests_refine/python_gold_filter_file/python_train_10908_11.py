mod = 10 ** 9 + 7

n, k = map(int, input().split())
otv = 0
D = [0] * (k + 1)
for i in range(1, k + 1):
    D[i] = pow(k // i, n, mod)

for i in range(k // 2, 0, -1):
    for j in range(i * 2, k + 1, i):
        D[i] -= D[j]

for i in range(1, k + 1):
    otv = (otv + D[i] * i) % mod

print(otv)