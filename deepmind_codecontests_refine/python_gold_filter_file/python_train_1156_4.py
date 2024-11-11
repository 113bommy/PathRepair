N = int(input())
prime_factors = {}
 
i = 2
while True:        
    if i*i > N:
        if N in prime_factors:
            prime_factors[N] += 1
        else:
            prime_factors[N] = 1
        break
    
    if N%i == 0:                    # factors are necessarily prime numbers
        if i in prime_factors:
            prime_factors[i] += 1
        else:
            prime_factors[i] = 1
        
        N //= i
        continue
    
    i += 1
        
 
ans1 = 1
for prime in prime_factors.keys():
    ans1 *= prime
 
ans2 = 0
while (1 << ans2) < max(prime_factors.values()):
    ans2 += 1
ans2 += 1           # Assuming that flattening is a given.
    
temp = list(prime_factors.values())[0]
for num in prime_factors.values():
    if temp != num: break
else:
    while temp%2 == 0:
        temp //= 2
    if temp == 1:
        ans2 -= 1
        
print(ans1, ans2)