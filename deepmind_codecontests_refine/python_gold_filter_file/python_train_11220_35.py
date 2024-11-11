n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=1
for i in range(n):
    ans*=a[i]
    if ans>10**18:print(-1);exit()
print(ans)