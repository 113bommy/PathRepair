H,W = map(int,input().split())

A = [list(map(int,input().split())) for _ in range(H)]

results = []

for y in range(H):
  for x in range(W-1):
    if A[y][x] % 2 == 1:
      A[y][x] -= 1
      A[y][x+1] += 1
      results.append((y+1,x+1,y+1,x+2))

  if y != H-1 and A[y][W-1] % 2 == 1:
    A[y][W-1] -= 1
    A[y+1][W-1] += 1
    results.append((y+1, W, y+2, W))

print(len(results))
for r in results:
  print(*r)