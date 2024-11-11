N,Q,S,*L = open(0).read().split()
N,Q = int(N),int(Q)
ans = N
l = -1
r = N
while l+1<r:
  s = (l+r)//2
  i = s
  p = S[i]
  for t,d in zip(*[iter(L)]*2):
    if p!=t:
      continue
    if d=='L':
      if i==0:
        l = s
        break
      i -= 1
      p = S[i]
    else:
      if i==N-1:
        r = s
        break
      i += 1
      p = S[i]
  else:
    r = s
ans -= r
l = -1
r = N
while l+1<r:
  s = (l+r)//2
  i = s
  p = S[i]
  for t,d in zip(*[iter(L)]*2):
    if p!=t:
      continue
    if d=='L':
      if i==0:
        l = s
        break
      i -= 1
      p = S[i]
    else:
      if i==N-1:
        r = s
        break
      i += 1
      p = S[i]
  else:
    l = s

ans -= N-r  
print(ans)
