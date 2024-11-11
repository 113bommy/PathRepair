n=int(input())
d=[]
ans=0
for i in range(n):
    tmp=[int(j) for j in input().split()]
    d.append(tmp)
for i in range(n):
    for j in range(i+1,n):
        ans+=d[i][j]

for i in range(n):
    for j in range(i+1,n):
        for k in range(n):
            if i==k or j==k:
                continue
            if d[i][j]>d[i][k]+d[k][j]:
                print(-1)
                exit()
            elif d[i][j]==d[i][k]+d[k][j]:
                ans-=d[i][j]
                break
print(ans)
