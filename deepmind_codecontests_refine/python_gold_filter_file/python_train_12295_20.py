n, k = [int(i) for i in input().split()]
if k == 0 : print(0)
elif n >= k : print(1)
else :
	if k % n == 0:
		print(k // n)
	else :
		print(k // n + 1)