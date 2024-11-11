import math
def solve(arr, n, c):
	mx = -math.inf
	
	for i in range(1,n):
		mx = max(mx, arr[i-1]-arr[i])
	
	if mx > c:
		return mx - c
	else:
		return 0
	
n, c = list(map(int, input().strip().split()))
arr = list(map(int, input().strip().split()))
result = solve(arr, n, c)
print(result)