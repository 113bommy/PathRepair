N,X,M=map(int, input().split())
A=[X]
for i in range(1,M+1):
  d=pow(A[i-1],2,M)
  if d in A:
    break
  A.append(d)
c=A.index(d)
e=len(A)
cy=e-c
ans=0
if N<=e:
  for i in range(N):
    ans+=A[i]
  print(ans)
else:
  m=sum(A[:c])
  n=sum(A[c:e])
  #print(m,n)
  f=(N-c)//cy
  ans=m+n*f+sum(A[c:c+((N-c)%cy)])
  print(ans)
