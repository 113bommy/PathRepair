N, A, B , *h = map(int, open(0).read().split())
C = A-B
l = -1
r = 10**20
while l+1<r:
  s = (l+r)//2
  M = [c-s*B for c in h]
  cnt = sum((c+C-1)//C if c>0 else 0 for c in M)
  if cnt>s:
    l = s
  else:
    r = s
print(r)