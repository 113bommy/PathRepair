n, x = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

MOD = 10 ** 9 + 7

S = [0] * (x+1)
T = [0] * (x+1)

S[x] = 1

for i in range(n-1, -1, -1):
    T = [0] * (x + 1)
    for j in range(x+1):
        S[j] %= MOD
        T[j] += S[j] * i % MOD
        T[j % a[i]] += S[j]
    S, T = T, S

print(sum(i * S[i] % MOD for i in range(a[0]) ) % MOD)
