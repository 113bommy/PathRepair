g=[0,2,0,1,0,1,0,0,1,0,1,0]
a,b=map(int,input().split())
print('Yes' if g[a-1]==g[b-1] else 'No')