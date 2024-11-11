x,y=map(int,input().split())
g=[0,1,3,1,2,1,2,1,1,2,1,2,1]
if g[x]==g[y]:
    print('Yes')
else:
    print('No')