parent=[i for i in range(200005)]
size=[1 for i in range(200005)]
def find(v):
    if v == parent[v]:
        return v
    parent[v]=find(parent[v])
    return parent[v]
def union(a,b):
    a=find(a)
    b=find(b)
    if a is not b:
        if size[a] < size[b]:
            a,b=b,a
        parent[b]=a
        size[a] += size[b]

########################
########################

n,m=map(int,input().split())
a=[[False for i in range(110)]for j in range(110)]
for i in range(n):
    k=list(map(int,input().split()))
    for j in range(1,len(k)):
        a[i][k[j]-1]=True
flag=False
for i in range(n):
    for j in range(m):
        if a[i][j]:
            flag=True
if flag == False:
    print(n)
else:
    for i in range(n):
        for j in range(i+1,n):
            for k in range(m):
                if a[i][k] and a[j][k]:
                    union(i,j)
    cnt=0
    for i in range(n):
        if find(i)==i:
            cnt += 1
    print(cnt-1)