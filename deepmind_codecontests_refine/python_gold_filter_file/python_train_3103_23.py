ans=10**10
n=int(input())
w=list(map(int,input().split()))
for i in range(1,n):
    ans=min(ans,abs(sum(w[:i])-sum(w[i:])))

print(ans)