
n, m = map(int, input().split())
d = {}
for _ in range(m):
     a, b = input().split()
     d[a] = b
     d[b] = a
c = list(input().split())
res = []
for w in c:
     m = w if len(w) <= len(d[w]) else d[w]
     res.append(m)
print(*res)
