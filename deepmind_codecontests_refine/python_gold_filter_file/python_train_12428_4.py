n=int(input())
a=list(map(int,input().split()))
ans=0
a.sort()
for i in range(0,n):
    ans+=abs(i+1-a[i])
print(ans)