from math import gcd
from math import sqrt
n = int(input())
t = int(sqrt(n))+1
k = n
for i in range(2,t):
	if not n%i:
		k = gcd(k,i)
		k = gcd(k,n//i)
print(k)
