'''input
8 6
1 2 1 3 3 5 2 1
1 3
2 3
2 4
8 8
1 4
5 8
'''
from sys import stdin
import sys
import copy
sys.setrecursionlimit(15000)


def create_dp(arr, n):
	dp1 = [-1] * n
	dp1[-1] = n - 1

	for i in range(n - 2, -1, -1):
		if arr[i] <= arr[i + 1]:
			dp1[i] = dp1[i + 1]
		else:
			dp1[i] = i

	dp2 = [-1] * n
	dp2[-1] = n - 1
	for i in range(n - 2, -1, -1):
		if arr[i] >= arr[i + 1]:
			dp2[i] = dp2[i + 1]
		else:
			dp2[i] = i
	return dp1, dp2


# main starts
n, m = list(map(int, stdin.readline().split()))
arr = list(map(int, stdin.readline().split()))
dp1, dp2 = create_dp(arr, n)
for _ in range(m):
	l, r = list(map(int, stdin.readline().split()))
	if dp2[dp1[l - 1]] >= r - 1:
		print("Yes")
	else:
		print("No")