n = int(input())
mod = 998244353
*arr, = map(int, input().split())
arr.sort()
i = 0
j = 2 * n - 1
s = 0
while i < j:
    s += abs(arr[i] - arr[j])
    i += 1
    j -= 1

s %= mod

factorials = [1]
for i in range(1, 2 * n + 1):
    factorials.append((factorials[-1] * i) % mod)

inverses = [pow(v, mod - 2, mod) for v in factorials]

def cnk(n, k):
    return (factorials[n] * inverses[k] * inverses[n - k]) % mod

print((s * cnk(2 * n, n)) % mod)
