n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
s=sum(A)
ans=0
for a in A:
    ans += a*(s-a)
print((ans//2)%mod)