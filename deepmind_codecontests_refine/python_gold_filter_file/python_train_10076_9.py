n=int(input())
p=list(map(int,input().split()))
ans,m=0,p[0]
for i in range(n):
    m=min(m,p[i])
    if m==p[i]: ans+=1
print(ans)