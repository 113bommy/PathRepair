'''input
3


'''
prime=[True]*100000
n=int(input())
prime[1] = False
primes=[]
for i in range(2,100000):
	if(prime[i]):
		primes.append(i)
		j = 2*i
		while(j<100000):
			prime[j] = False
			j+=i
if(n==2):
	print(-1)
	exit(0)
a = 1
for i in range(0,n):
	a *= primes[i]
for i in range(0,n):
	print(a//primes[i])
	# a/=primes[i]
