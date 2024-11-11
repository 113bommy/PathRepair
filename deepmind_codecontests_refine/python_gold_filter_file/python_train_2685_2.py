import math
from functools import reduce
def lcm_base(x, y):
    return (x * y) // math.gcd(x, y)

def lcm(*numbers):
    return reduce(lcm_base, numbers, 1)

N,M = map(int,input().split())
a = list(map(lambda a: int(a)//2, input().split()))
g = lcm(*a)
if any([g // item % 2 == 0 for item in a]):
    print(0)
else:
    ans = M//g
    ans = max(math.ceil(ans/2),0)   
    print(ans)