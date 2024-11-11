[n,m]=[int(x) for x in input().split()]
g={}
for i in range (0,m):
    h=input().split()
    g[h[0]]=h[1]

f=input().split()
for i in f:
    if len(i)<=len(g[i]):
        print(i, end=' ')
    else:
        print(g[i], end=' ')
