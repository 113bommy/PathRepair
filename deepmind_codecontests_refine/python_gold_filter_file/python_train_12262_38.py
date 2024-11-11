K = int(input())
import math
i = 0
l = list(range(K+1))[1:]

for a in l:
    for b in l:
        for c in l:
            i += math.gcd(math.gcd(a,b), c)
print(i)
