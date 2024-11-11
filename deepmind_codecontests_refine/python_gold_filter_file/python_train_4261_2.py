import bisect
primes = [0, 0] + [1]*32767
for i in range(2, 182):
    if primes[i]:
        for j in range(i*i, 32769, i):
            primes[j] = 0

prime_value = [i for i in range(2, 32769) if primes[i]]
while True:
    n = int(input())
    if n == 0:
        break
    x = bisect.bisect_left(prime_value, n//2)
    y = bisect.bisect_left(prime_value, n)
    values = prime_value[x:y]
    print(sum(1 for v in values if primes[n-v]))