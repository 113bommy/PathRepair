n=int(input())
a=list(map(int,input().split()))

ans=1
a.sort()
for i in range(n):
    ans*=a[i]
    if ans>10**18:
        ans=-1
        break
print(ans)
