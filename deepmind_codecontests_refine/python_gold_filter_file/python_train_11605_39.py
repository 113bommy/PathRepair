a, m = map(int, input().split())

while not m%2:
	m >>= 1
if(a%m==0):
	print('Yes')
else:
	print('No')