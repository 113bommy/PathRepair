def primes_method5(n):
    out = list()
    sieve = [True] * (n+1)
    for p in range(2, n+1):
        if (sieve[p]):
            out.append(p)
            for i in range(p, n+1, p):
                sieve[i] = False
    return out


n=int(input())
z=[]
i=2
c=0
while i<=n:
        count=0
        for j in primes_method5(i):
            if i%j==0: count+=1
        if count==2: c+=1
        i+=1
if n>=1 and n<6: print(0)
else:print(c)


