for i in range(int(input())):
	n, k1, k2 = list(map(int,input().split()))
	k1_s = list(map(int,input().split()))
	k2_s = list(map(int,input().split()))
	
	if max(k1_s) > max(k2_s):
		print('YES')
	
	else:
		print('NO')	