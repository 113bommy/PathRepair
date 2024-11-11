n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
sum_a=sum(A)
ans=0
for a in A:
    ans += a*(sum_a-a)
print((ans//2)%mod)