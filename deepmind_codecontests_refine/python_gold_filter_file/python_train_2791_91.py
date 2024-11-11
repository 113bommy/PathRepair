n, k = map(int, input().split())
*H, = map(int, input().split())
DP = [0 for i in range(n)]
for i in range(1, n):
    DP[i] = min([DP[i-j]+abs(H[i]-H[i-j]) for j in range(1, min(i, k)+1)])
print(DP[n-1])
