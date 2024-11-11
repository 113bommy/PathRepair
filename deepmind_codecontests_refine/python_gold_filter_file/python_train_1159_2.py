n=int(input())
lst=list(map(int,input().split()))
lst.sort()
res=[]
for i in range(1,n,2):
    res.append(lst[i])
if n%2==0:
    for i in range(n-2,-1,-2):
        res.append(lst[i])
else:
    for i in range(n-1,-1,-2):
        res.append(lst[i])
print(*res)