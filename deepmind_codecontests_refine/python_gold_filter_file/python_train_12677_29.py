import bisect
n,m,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=0

A,B=[0],[0]
for i in range(n):
  A.append(a[i]+A[i])
for i in range(m):
  B.append(b[i]+B[i])

for j in range(n+1):
  K=k-A[j]
  if K<0:
    break
  else:
    ans=max(ans,bisect.bisect_right(B,K)+j-1)
print(ans)
    