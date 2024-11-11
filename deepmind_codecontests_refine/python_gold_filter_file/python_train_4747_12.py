n, k = map(int, input().split())
d = k * k + k >> 1
s, m = 1, n // d

if n < d:
    print(-1)
    exit()
    
for q in range(2, 100001):
    if n % q == 0:
        if s < q <= m: s = q
        if s < n // q <= m: s = n // q

for q in list(range(s, s * k, s)) + [n - (d - k) * s]: print(q)