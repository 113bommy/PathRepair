import sys
input = sys.stdin.readline

N,K = map(int,input().split())
H = [0]+list(map(int,input().split()))+[0]

DP=[[1<<60]*(K+1) for i in range(N+2)]

for k in range(K+1):
    DP[0][k]=0

for i in range(1,N+2):
    
    for k in range(K+1):
        for j in range(k+1):
            DP[i][k]=min(DP[i][k],DP[i-j-1][k-j]+max(0,H[i]-H[i-j-1]))
        
print(min(DP[-1]))
