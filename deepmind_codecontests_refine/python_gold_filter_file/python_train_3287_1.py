n, m, k = map(int, input().split())
f = lambda k, s: (2 * s - k + 1) * k - s if k < s else (s - 2) * s + 2 * k
s, m = m // n + 1, 2 * m + 1
while f(k, s) + f(n - k + 1, s) < m: s += 1
print(s - 1)