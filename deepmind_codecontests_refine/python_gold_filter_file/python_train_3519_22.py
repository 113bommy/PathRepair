import bisect
n,k=map(int, input().split())
V=list(map(int, input().split()))
ans=0
for i in range(k+1):
  for j in range(k+1-i):
    if i+j>n:
      break  
    #手に取りだしたもの
    A=sorted(V[:i]+V[n-j:])
    a=min(k-i-j,bisect.bisect_left(A, 0))
    ans=max(ans,sum(A[a:]))
print(ans)