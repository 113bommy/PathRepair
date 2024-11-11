n, q = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(n-1)]
ab.sort()
px = [list(map(int, input().split())) for i in range(q)]
p = [0 for i in range(n)]
for i in px:
  p[i[0] - 1] += i[1]
s = ""
for i in ab:
  p[i[1]-1] += p[i[0]-1]
print(" ".join(map(str, p)))