n,m=map(int,input().split())
l=[list(map(int,input().split())) for i in range(m)]
l.sort(key=lambda x:x[1])
lb=0
ans=0
for a,b in l:
    if a>=lb:
        lb=b
        ans+=1
print(ans)