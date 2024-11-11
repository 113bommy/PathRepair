def gcd(x,y):
	while y!=0: x,y=y,x%y
	return x
def lcm(x,y):
	_lcm=(x*y/gcd(x,y))
	if int(_lcm)==_lcm: return int(_lcm)
	else: return 0
def BiggestLCM(n):

	_b=False
	k=n-1
	LCM=n*k
	U=LCM
	i=n-2
	while gcd(LCM,i)!=1 and i>0:
		if lcm(LCM,i)>U: U=lcm(LCM,i)
		i-=1
	a=1
	if i>0:
		a=LCM*i
	if a>U:return(a)
	return(U)
n=int(input())
if n>2 and n%2==0:
	print (max([BiggestLCM(n),BiggestLCM(n-1)]))
else: print(BiggestLCM(n))