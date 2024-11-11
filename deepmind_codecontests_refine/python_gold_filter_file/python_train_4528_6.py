n = int(input())
l = sorted(list(map(int , input().split())))
ans=0
tmp=l[0]
for i in range(1,n):
    while tmp >= l[i]:
        l[i]+=1
        ans +=1
    tmp=l[i]
print(ans)