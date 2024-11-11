h,w=map(int,input().split())
c=list()
from sys import exit
for _ in range(h):c.append([2]*w)
for i,e in enumerate(input().split()):
    if int(e)==w:c[i]=[1]*w
    else:
        for j in range(int(e)):
            c[i][j]=1
        c[i][int(e)]=0
for i,e in enumerate(input().split()):
    for j in range(int(e)):
        if not c[j][i]:
            print(0);exit()
        c[j][i] = 1
    if int(e)!=h:
        if c[int(e)][i]==1:print(0);exit()
        c[int(e)][i]=0
ans=0
for i in range(h):
    for j in range(w):
        ans+=c[i][j]==2
print((2**ans)%(10**9+7))
