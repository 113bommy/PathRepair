N = int(input())
arr = []*N
for _ in range(N):
	arr.append(list(map(int,input().split())))

dp = [0,0,0]
for a in arr:
	dp = [a[0]+max(dp[1],dp[2]),a[1]+max(dp[0],dp[2]),a[2]+max(dp[0],dp[1])]

print(max(dp))