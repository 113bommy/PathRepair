f = lambda: map(int, input().split())
g = lambda: m - l * p[l - 1] + s[l]

n, A, x, y, m = f()
t = sorted((q, i) for i, q in enumerate(f()))
p = [q for q, i in t]
s = [0] * (n + 1)
for j in range(n): s[j + 1] = p[j] + s[j]

l = r = n
F = L = R = B = -1
while 1:
    if p:
        while l > r or g() < 0: l -= 1
        b = min(p[l - 1] + g() // l, A)
    else: b, l = A, 0

    f = x * (n - r) + y * b
    if F < f: F, L, R, B = f, l, r, b

    if not p: break
    m += p.pop() - A
    r -= 1
    if m < 0: break

print(F)

p = [(i, B if j < L else q if j < R else A) for j, (q, i) in enumerate(t)]
for i, q in sorted(p): print(q)