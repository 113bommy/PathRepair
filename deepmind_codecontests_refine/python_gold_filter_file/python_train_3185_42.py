#import numpy
import math
a,b=[int(x) for x in input().split()]
z=math.log(b)-math.log(a)
q=math.log(3)-math.log(2)
n=int(z/q)+1
limax=a*(3**(n))
#print(limax)
bob=b*(2**(n))
#print(bob)
if limax > bob:
    print(n)
else:
    print(n+1)
