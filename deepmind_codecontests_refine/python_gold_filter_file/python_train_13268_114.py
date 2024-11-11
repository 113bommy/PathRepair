n = int(input())
count = 0
for k in range(0,n):
	a, b = map(int, input().split())
	if ( b - a >= 2 ):
		count += 1
print(count)