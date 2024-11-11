N,K=map(int,input().split())
A=list(map(int,input().split()))
from fractions import gcd
g=A[0]
for a in A[1:]:
    g=gcd(g,a)
print(['IMPOSSIBLE','POSSIBLE'][(g==1 or K%g==0) and max(A)>=K])