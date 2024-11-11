n=int(input())
l=list(map(int,input().split()))
l.sort()
ans=1
for i in range(n):
    ans*=l[i]
    if ans>10**18:
        ans=-1
        break 
print(ans)