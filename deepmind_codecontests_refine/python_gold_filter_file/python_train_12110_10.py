n,m=map(int,input().split())
d=[input() for u in range(n)]
l=[]
x=0
for i in zip(*d):
    l.append(max([int(j) for j in i]))
for i in range(n):
    for j in range(m):
        if(int(d[i][j])==l[j]):
            x=x+1
            break
print(x)
