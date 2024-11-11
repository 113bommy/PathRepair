class Solution():
	def number_or_ways(start, end, moves):
		p = 10**9+7
		num_rots = 0
		for i in range(len(start)):
			rot = start[i:]+start[0:i]
			if rot == end:
				num_rots += 1

		dp = [[0 for i in range(2)] for j in range(moves+1)]

		dp[0][0], dp[0][1] = 1, 0

		for i in range(1, moves+1):
			dp[i][0] = (((num_rots-1)*dp[i-1][0])%p + ((len(start)-num_rots)*dp[i-1][1])%p)%p
			dp[i][1] = ((num_rots*dp[i-1][0])%p + ((len(start)-1-num_rots)*dp[i-1][1])%p)%p

		if start == end:
			return dp[moves][0]
		else:
			return dp[moves][1]

start = input().strip()
end = input().strip()

moves = int(input())

print(Solution.number_or_ways(start, end, moves)) 

