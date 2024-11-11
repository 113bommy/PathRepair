n, k = map(int, input().split())
s, t = 0, list(map(int, input().split()))

for i in range(1, n):
    t[i] += t[i - 1]
t = [t[k - 1]] + [t[i + k] - t[i] for i in range(n - k)]
p = [(t[i], i) for i in range(n - k + 1)]
p.reverse()
for i in range(1, n - k):
    if p[i][0] < p[i - 1][0]: p[i] = max(p[i], p[i - 1])
p.reverse()

a, b = 0, 0
for i in range(n - 2 * k + 1):
    if p[i + k][0] + t[i] > s:
        s = p[i + k][0] + t[i]
        a, b = i, p[i + k][1]
print(a + 1, b + 1)