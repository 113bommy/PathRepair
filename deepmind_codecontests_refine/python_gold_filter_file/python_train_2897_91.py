def solve():
    N = int(input())
    S2 = [0]*N
    for i in range(N):
        S2[i] = input()
    ans = 0
    for k in range(N):
        cum = [[0]*(N+1) for _ in range(N+1)]
        for i in range(1,N+1):
            for j in range(1,N+1):
                cum[i][j] = cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]+(S2[i-1][j-1]==S2[(j-1+k)%N][(i-1-k)%N])
                if i==N and j==N:
                    ans += (cum[i][j]==N*N)*N
    return ans
print(solve())