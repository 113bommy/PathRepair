def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors
#print(prime_factors(48))
n=int(input())
if n==1:print(1)
elif n==2:
    print(2)
else:
    kk=prime_factors(n)
    #print(kk)
    if len(set(kk))==1:
        print(kk[0])
    else:
        print(1)
    
    
    
    
    