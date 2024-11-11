N, M = map(int, input().split())

A = list(map(int, input().split()))
B = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]

DP = [-1]*(N+1)
DP[0] = 0 

for i in range(N):
    for j in A:
        if i+B[j] <= N:
            DP[i+B[j]] = max(DP[i]*10+j, DP[i+B[j]])

print(DP[N]) 