import math

a,b,n = [int(i) for i in input().split()]

chance = 0

while n>=0:

    if chance == 1:

        n -= math.gcd(n,b)
        chance = 0

    else:

        n -= math.gcd(n,a)
        chance = 1

    #print (chance)

print (chance)
