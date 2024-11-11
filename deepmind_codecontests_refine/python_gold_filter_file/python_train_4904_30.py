from sys import*
import math
n = int(input())
i = 1
a,b = [],[]
l = int((n*(n+1))/2)
found = False
while(i <= int(l/2)):
	if(math.gcd(i,(l - i)) > 1):
		print("Yes")
		x = int(math.sqrt(2*i))
		while((x)*(x+1) < 2*i):
			x = x+1
		k = 1
		while(k<x):
			a.append(k)
			k = k+1
		t = int((x*(x+1))/2)
		#z = ((x-1)*x)/2
		m = t-i
		#a.remove(a[-1])
		if(m != 0):
			a.remove(m)
		a.append(x)
		for j in range(1,n+1):
			if(j not in a):
				b.append(j)
		print(len(a) , *a, sep = ' ')
		print(len(b) , *b, sep = ' ')
		found = True
		break
	i = i+1
if(not found):
	print("No")