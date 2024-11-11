n,m=map(int,input().split())

x=[[] for i in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    if b not in x[a-1]:
        x[a-1].append(b)
        if a not in x[b-1]:
            x[b-1].append(a)

ans=0

while True:
    idx,flg=0,0
    for i in x:
        if len(i)==1:
            flg=1
            x[i[0]-1].remove(idx+1)
            x[idx]=[]
            ans+=1
        idx+=1
    if flg==0:
        break
print(ans)
