n,m=map(int,input().split())
ans=[]
for j in range(m):
    a = list(map(int,input().split()))
for i in range(n):ans.append(i%2)           
print(*ans,sep='')