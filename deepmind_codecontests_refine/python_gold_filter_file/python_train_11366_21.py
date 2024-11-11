f=lambda a, b: a if b==0 else f(b, a%b)
a,b,n = map(int,input().split())
c=2
while n>0:
	c ^= 3
	n -= [f(a,n),f(b,n)][c-1]
print(c-1)