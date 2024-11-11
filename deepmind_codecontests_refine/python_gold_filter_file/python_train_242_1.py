from math import gcd

n = int(input())
if n<=2:
	print(n)
elif not n%6:
	print((n-1)*(n-2)*(n-3))
elif not n%2:
	print(n*(n-1)*(n-3))
else:
	print(n*(n-1)*(n-2))


#  C:\Users\Usuario\HOME2\Programacion\ACM