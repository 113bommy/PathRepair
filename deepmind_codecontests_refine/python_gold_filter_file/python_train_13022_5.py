n, m=map(int,input().split())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
exist=[]
for i in l:
    for j in range(i[0],i[1]+1):
        exist.append(j)
    
al=[i for i in range(1,m+1)]

ans=[]

for i in al:
    if i not in exist:
        ans.append(i)
print(len(ans))
print(*ans)
