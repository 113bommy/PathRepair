n, q = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(n-1)]
ab.sort()
p = [0]*n
for i in range(q):
  a, b = map(int, input().split())
  p[a - 1] += b
s = ""
for i in ab:
  p[i[1]-1] += p[i[0]-1]
print(" ".join(map(str, p)))