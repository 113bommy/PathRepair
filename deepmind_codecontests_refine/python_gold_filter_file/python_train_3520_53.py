inf = float('inf')

def accmulate(array):
    global cs
    cs = [0]*(len(array)+1)
    for i in range(len(array)):
        cs[i+1] = cs[i] + array[i]

def query(l,r):
    return cs[r+1] - cs[l]

N = int(input())
A = list(map(int,input().split()))

accmulate(A)

dp = [[inf]*(N+1) for _ in range(N+1)]

for i in range(N):
    dp[i][i+1] = 0

for i in range(N-1):
    dp[i][i+2] = A[i] + A[i+1]

for b in range(3,N+1):
    for i in range(N-b+1):
        j = i + b
        for k in range(i+1,j):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + query(i,j-1))

ans = dp[0][N]
print(ans)