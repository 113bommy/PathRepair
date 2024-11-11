n=int(input())
a=2**n
if (n>=13):
	a-=2**(n-13)*100
print(a)