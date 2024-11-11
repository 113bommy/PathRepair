
(n, a, b) = list(map(int, input().split()))
h = list(map(int, input().split()))

h.sort()
d1 = h[b-1]
d2 = h[-a]

print(d2 - d1)