from itertools import permutations
def getdigits(x):
    if x==0:
        return 1
    digs=0
    while x!=0:
        x//=7
        digs+=1
    return digs
n,m=map(int,input().split())
a,b=(getdigits(n-1),getdigits(m-1))
c=a+b
if c>7:
    print(0)
    exit(0)
combs=permutations(range(7),c)
ans=0
for comb in combs:
    d=comb[:a]
    e=comb[a:]
    f=""
    g=""
    for i in d:
        f+=str(i)
    for i in e:
        g+=str(i)
    x=int(f,7)
    y=int(g,7)
    if x<n and y<m:
        ans+=1
print(ans)
