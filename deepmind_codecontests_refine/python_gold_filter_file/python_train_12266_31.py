from fractions import *
N,X0=map(int,input().split())
X=list(map(int,input().split()))
ans=abs(X[0]-X0)
for i in range(1,N):
    ans=gcd(ans,abs(X[i]-X0))
print(ans)