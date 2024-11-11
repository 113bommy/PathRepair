from math import gcd
n = int(input())
a = int(input())
b = int(input())
g = gcd(a,b)
if n%g!=0: print("NO")
else:
	x = n//b
	while x>=0:
		if (n-(b*x))%a==0: print("YES");print((n-(b*x))//a,x);break
		x-=1
	else: print("NO")