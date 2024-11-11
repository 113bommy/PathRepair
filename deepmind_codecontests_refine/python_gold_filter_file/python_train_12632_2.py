INF=int(1e9)
req=[]
xs=[[] for i in range(2017)]
seen=[0]*5040

m=int(input())
n=0
for i in range(m):
    s,x=input().split()
    x=int(x)
    if s=='win':
            xs[x].append(i)
    else:
        max_first=0
        if len(xs[x]):
            for j in range(len(xs[x])):
                max_first=max(max_first,xs[x][j])
            req.append((xs[x][j],i,x))
            n+=1
def cmp(r):
    return -r[2]
req.sort(key=cmp)

ans=0
for i in range(n):
    compatible=1
    for j in range(req[i][0],req[i][1]+1):
        if seen[j]:
            compatible=0
            break
    if compatible:
        ans+=2**req[i][2]
        for j in range(req[i][0],req[i][1]+1):
           seen[j]=1
print(ans)        
