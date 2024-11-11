def sieve(n):
	p=[True]*(n+1)
	p[0]=p[1]=False
	for i in range(2,int((n+1)*0.5)+1):
		if p[i]==True:
			for j in range(i*i,n+1,i):
				p[j]=False
	prime=[]
	for i in range(n+1):
		if p[i]==True:
			prime.append(i)
	return prime

def solve(n):
	i=0
	while True:
		if n>prime[i]:
			a=prime[i]
		elif n==prime[i]:
			a=prime[i-1]
		else:
			b=prime[i]
			break
		i+=1
	print(a,b)

prime=sieve(50021)
while True:
	try:
		n=int(input())
		solve(n)
	except EOFError:
		break