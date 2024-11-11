N = int(input())
A = list(map(int, input().split()))
sm=0
mod=10**9+7
s=sum(A)
for i in A:
    s-=i
    sm+=i*s
    sm%=mod
print(sm)