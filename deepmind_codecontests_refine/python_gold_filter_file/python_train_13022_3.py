n,m =map(int,input().split())
arr=[]
for i in range(n):
    x, y = map(int,input().split())
    if(x==y):arr.append(x)
    for j in range(x,y+1):
        arr.append(j)
ans=[]
for i in range(1,m+1):
    if(i  in arr):continue
    ans.append(i)
print(len(ans))
print(*ans)


