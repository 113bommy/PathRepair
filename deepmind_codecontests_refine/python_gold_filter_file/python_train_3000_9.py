N, M = map(int, input().split())
A = [int(a) for a in input().split()]
L = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
A.sort(reverse = True)
#print(A)
dp = [0] + ([-1]*N)
#print(dp)
for i in range(1, N+1):
    for a in A:
        if L[a] <= i:
            dp[i] = max(dp[i], dp[i-L[a]] * 10 + a)
#print(dp)
print(dp[-1])
