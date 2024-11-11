# your code goes here
import math
mod = 1000000007
def power(x,y):
	ans = 1
	while(y):
		if y&1:
			ans = ((ans%mod)*(x%mod))%mod
		x = ((x%mod)*(x%mod))%mod
		y = y//2;
	return ans
	
def prime(x):
	fact = []
	if x%2 == 0:
		fact.append(2)
		while x%2==0:
			x //= 2
	for i in range(3,int(math.sqrt(x))+1, 2):
		if x%i==0:
			fact.append(i)
			while(x%i==0):
				x//=i
	if(x>1):
		fact.append(x)
	return fact
	
x, n = map(int, input().split())
factors = prime(x)
ans = 1;
for factor in factors:
	p = factor
	while(n//p):
		cnt = n//p
		p *= factor
		ans = ((ans%mod)*(power(factor, cnt)%mod))%mod
print(ans%mod)