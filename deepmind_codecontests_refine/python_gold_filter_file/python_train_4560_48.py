n,k=map(int,input().split())
A=[int(i) for i in input().split()]
F=[int(i) for i in input().split()]
A.sort()
F.sort()

def chk(x):
  ct=0
  for i in range(n):
    a,f=A[i],F[-i-1]
    ct+=max(0,a-x//f)
  if ct<=k:
    return True
  else:
    return False


l,r=0,A[-1]*F[-1]
while r-l>1:
  m=(l+r)//2
  if chk(m):
    r=m
  else:
    l=m

if chk(l):
  print(l)
else:
  print(r)
