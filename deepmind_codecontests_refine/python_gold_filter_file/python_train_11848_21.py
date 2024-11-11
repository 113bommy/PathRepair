n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=0
for i in range(n):
    c=min(a[i],b[i])
    a[i]-=c
    b[i]-=c
    d=min(b[i],a[i+1])
    a[i+1]-=d
    ans+=c+d
print(ans)