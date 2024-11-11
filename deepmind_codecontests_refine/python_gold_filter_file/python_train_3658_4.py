import math

t = int(input())

while t>0:
	t -= 1;
	n = int(input())
	m = n
	ans = 2
	while n>1:
		n=n//2
		ans *= 2
	ans -= 1
	k = 1
	if ans == m:
		a1 = math.sqrt(ans)
		a = int(a1)
		for i in range(2,a+1):
			if(ans%i==0):
				k=i
				break;
		if k == 1:
			k = ans
	ans = ans//k
	print(ans)