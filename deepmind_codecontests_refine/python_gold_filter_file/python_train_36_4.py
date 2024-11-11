from collections import Counter
n = int(input())
cnt = Counter(input())
if cnt['I']:
	if cnt['I'] == 1:
		print(1)
	else:
		print(0)
else:
	print(cnt['A'])
