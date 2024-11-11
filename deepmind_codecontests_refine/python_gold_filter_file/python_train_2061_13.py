S = input()

if 'R' in S[1::2]:
	print('No')
elif 'L' in S[::2]:
	print('No')
else:
	print('Yes')