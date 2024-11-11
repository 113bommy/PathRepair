for testcase in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	
	if n == 1:
		print(int(a[0] == 1))
		continue
	
	dp1, dp2 = [-1]*n, [-1]*n
	dp1[n-1], dp2[n-1] = 0, int(a[n-1] == 1)
	dp1[n-2], dp2[n-2] = 0, int(a[n-2] == 1)
	
	i = n-3
	while i >= 0:
		dp1[i] = min(dp2[i+1], dp2[i+2])
		dp2[i] = min(int(a[i] == 1) + dp1[i+1], int(a[i] == 1) + int(a[i+1] == 1) + dp1[i+2])
		i = i - 1
	print(dp2[0])