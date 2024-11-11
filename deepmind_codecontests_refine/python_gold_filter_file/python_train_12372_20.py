n=int(input())
d=[]
for i in [0]*n:
    d.append([int(x) for x in input().split()])
from itertools import product
ans=0
for i,j in product(range(n),range(n)):
    flag=0
    for k in range(n):
        if d[i][j]>d[i][k]+d[k][j]:
            print(-1)
            import sys
            sys.exit()
        if d[i][j]==d[i][k]+d[k][j] and (k!=i and k!=j and i!=j ):
            flag=1
    if flag==0:
        ans+=d[i][j]
print(ans//2)