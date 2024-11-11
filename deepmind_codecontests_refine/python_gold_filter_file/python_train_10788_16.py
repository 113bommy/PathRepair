n = int(input())
pos = 0
neg = 0
for _ in range(n):
	x, y = map(int,input().split())
	if x > 0:
		pos+=1
	else:
		neg+=1
if (pos <= 1 and neg >= 1) or (neg <=1 and pos >= 1):
	print('yes')
else:
	print('no')