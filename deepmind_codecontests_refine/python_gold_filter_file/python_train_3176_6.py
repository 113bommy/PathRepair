nt = list(map(int, input().split()))
if nt[0] == 1 and nt[1] >= 10:
	print(-1)
else:
	print(min(9, nt[1]) * 10 ** (nt[0] - 1))