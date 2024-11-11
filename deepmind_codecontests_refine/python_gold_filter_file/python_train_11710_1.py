n = int(input())

vertices   = []
for _ in range(n):
  x, w = map(int, input().split())
  vertices.append([x - w, x + w])
vertices = sorted(vertices, key = lambda x: x[1])

ans = 0
border = -(10**9 + 100)
for v in vertices:
  if border <= v[0]:
    ans += 1
    border = v[1]
print(ans)