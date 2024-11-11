n,m=map(int,input().split())
p=list(range(n+1))
h=[0]*(n+1)
def pred(x):
    if x!=p[x]: p[x]=pred(p[x]);
    return p[x]
def union(a,b):
    a,b=pred(a),pred(b)
    if h[a]<h[b]: a,b=b,a
    p[b]=a
    if h[a]==h[b]: h[a]+=1
for _ in range(m):
    i,j=map(int,input().split())
    union(i,j)
for i in range(n+1):
    pred(i)
print(2**(n-len(set(p))+1))