def isPrime(n):
	i = 2
	while (i * i <= n): 
		if (n % i == 0):
			return 0
		i += 1
	return n > 1
	
m = int(input())

if (m == 2):
	print(-1)
	exit(0)

i = 2
primes = []
while(len(primes) <= m + 1):
	if (isPrime(i)):
		primes.append(i);
	i += 1
p = 1
for j in range(0, m - 1):
	print(primes[j] * primes[m]);
	p *= primes[j]
print(p * primes[m - 1])
	