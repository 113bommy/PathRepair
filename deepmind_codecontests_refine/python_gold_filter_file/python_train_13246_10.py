#include <bits/stdc++.h>

import sys


for t in range(int(sys.stdin.readline())):
	n = int(sys.stdin.readline())
	a = tuple(map(int, sys.stdin.readline().split()))

	dp = [1 for i in range(n)]

	for i in range(2, n+1):
		sex = {0}
		for j in range(1, int(i**.5)+1):
			if i % j == 0:
				q = i//j
				if a[i-1] > a[j-1]:
					sex.add(dp[j-1])
				if j != q and a[i-1] > a[q-1]:
					sex.add(dp[q-1])
		dp[i-1] += max(sex)

	sys.stdout.write(f"{max(dp)}\n")
