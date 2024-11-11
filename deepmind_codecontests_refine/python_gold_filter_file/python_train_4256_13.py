n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=0
for i in range(0,2*n,2):
    ans+=a[i]
print(ans)
