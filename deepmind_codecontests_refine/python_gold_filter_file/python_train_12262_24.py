#c
import math
k=int(input())
print( sum(math.gcd(math.gcd(a,b),c) for a in range(1,k+1)for b in range(1,k+1)for c in range(1,k+1)) )