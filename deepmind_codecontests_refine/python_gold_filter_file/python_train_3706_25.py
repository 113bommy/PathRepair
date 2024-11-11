nm=input().split(" ")
n=int(nm[0])
m=int(nm[1])
primes=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
ni=primes.index(n)
if m in primes and primes.index(m)==ni+1:
    print('YES')
else:
    print('NO')