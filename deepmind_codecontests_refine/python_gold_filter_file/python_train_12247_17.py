

n, d = map(int, input().split())

A = input()



import functools

def solve():
	@functools.lru_cache(None)
	def dp(idx):
		if idx == n - 1: return 0
		ans = float('inf')
		for i in range(1, d + 1):
			if i + idx >= n: return ans
			if A[i + idx] == '1':
				ans = min(ans, 1 + dp(i + idx))
		return ans

	return dp(0)

ans = solve()
print(ans if ans != float('inf') else -1)