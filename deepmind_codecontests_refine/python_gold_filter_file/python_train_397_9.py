from collections import deque
H,W,K,*L = open(0).read().split()
L = [list(a) for a in L]
H,W,K = map(int, (H,W,K))
q = deque([])
step = [(-1,0),(1,0),(0,-1),(0,1)]
for i,a in enumerate(L):
  if 'S' in a:
    q = deque([(0,i,a.index('S'))])
    break
ans = 10**10
while q:
  c,a,b = q.popleft()
  x = min(a,H-a-1,b,W-b-1)
  cnt = 1+(x+K-1)//K
  ans = min(cnt,ans)
  if c+1>K:
    continue
  for dx,dy in step:
    n = a+dx
    m = b+dy
    if not(-1<n<H and -1<m<W):
      continue
    if L[n][m]=='.':
      L[n][m]='#'
      q.append((c+1,n,m))
print(ans)