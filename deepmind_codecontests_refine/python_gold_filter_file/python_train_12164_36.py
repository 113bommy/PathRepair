n = int(input())
t = list(map(int, input().split())) + [0]
v = list(map(int, input().split())) + [0]
m = sum(t)*2
g = [10**10]*(m+1)
l = [(0, 0, 0)]
for x, y in zip(t, v):
  l.append((l[-1][1], l[-1][1] + x*2, y))
for x, y, c in l:
  for i in range(m + 1):
    d = c
    if i < x:
      d += (x - i)*.5
    elif y < i:
      d += (i - y)*.5
    if g[i] > d:
      g[i] = d
print(sum(g)/2)