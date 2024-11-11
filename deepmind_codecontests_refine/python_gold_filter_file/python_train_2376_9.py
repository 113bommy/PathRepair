H, W = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(H)]

N = 0
ans = []
for hi in range(H):
  for wi in range(W-1):
    if a[hi][wi]%2 == 1:
      N += 1
      a[hi][wi+1] += 1
      ans.append((hi+1, wi+1, hi+1, wi+2))
      
for hi in range(H-1):
  if a[hi][-1]%2 == 1:
    N += 1
    a[hi+1][-1] += 1
    ans.append((hi+1, W, hi+2, W))
    
print(N)
for y, x, yp, xp in ans:
  print(y, x, yp, xp)