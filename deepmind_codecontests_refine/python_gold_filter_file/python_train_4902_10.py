n = int(input())
i = 1

while i <= n:
	if i % 3 == 0 or "3" in str(i):
		print(" ",end='')
		print(i,end='')
	i += 1
print()
