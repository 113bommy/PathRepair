n=int(input())
l=list(map(int,input().split()))
l.sort()
ans=(l[n-1]-l[0])*(l[2*n-1]-l[n])
for i in range(1,n):
    ans=min(ans,(l[n+i-1]-l[i])*(l[2*n-1]-l[0]))
            
print(ans)