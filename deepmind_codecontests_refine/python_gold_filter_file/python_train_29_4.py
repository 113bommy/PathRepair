import sys
input = sys.stdin.readline
MOD=(1e9)+7
t=int(input())
x=1
m=int(2*1e5+10)
dp=  [1 for i in range(m+1) ]
for i in range(10,m+1):
    dp[i]=(dp[i-10]+dp[i-9])%(MOD)
for _ in range(t):
    n,k=map(int,input().split())
    sums=0
    while n:
        sums  = (sums+dp[k+n%10])
        n = n//10
        sums %=MOD
    print(int(sums))
