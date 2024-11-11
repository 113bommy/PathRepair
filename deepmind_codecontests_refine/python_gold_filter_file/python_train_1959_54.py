import math
from functools import reduce
_=input()
print(reduce(math.gcd,map(int,input().split())))