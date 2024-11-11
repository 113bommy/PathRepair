n,m=map(int,input().split())
col=set([])
row=set([])
s=n*n
l=[]
for i in range(m):
    x,y=map(int,input().split())
    if x not in col and y not in row:
        s-=2*n-1-len(row)-len(col)
    elif y not in row and x in col:
        s-=n-len(col)
    elif x not in col and y in row:
        s-=n-len(row)
    l.append(s)
    col.add(x)
    row.add(y)
print(*l)