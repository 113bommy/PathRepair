import sys
input = sys.stdin.readline

N,S=map(int,input().split())
A=list(map(int,input().split()))

mod=998244353

DP=[0]*(S+1)
DP[0]=pow(2,N,mod)

INV=pow(2,mod-2,mod)

for a in A:
    for i in range(S-a,-1,-1):
        DP[i+a]=(DP[i]*INV+DP[i+a])%mod
        
print(DP[S])
