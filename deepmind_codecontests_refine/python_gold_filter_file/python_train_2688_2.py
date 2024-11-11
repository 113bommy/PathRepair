def gcd(a,b):
	x,y = min(a,b), max(a,b)
	while x*y>0:
		x,y = y%x,x
	return y

N,M=map(int,input().split())
S=input()
T=input()
g=gcd(N,M)
p,q=M//g,N//g
print((N//g)*M) if S[0::q]==T[0::p] else print('-1')