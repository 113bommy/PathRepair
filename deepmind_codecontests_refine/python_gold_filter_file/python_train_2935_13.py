n = int(input())
pattern1 = list('WB') * (n // 2)
pattern2 = list('BW') * (n // 2)
if n & 1:
	pattern1.append('W')
	pattern2.append('B')
for K in range(n):
	if K & 1:
		print(''.join(pattern2))
	else:
		print(''.join(pattern1))
