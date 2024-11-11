from functools import reduce
from fractions import gcd
n,k,*a=map(int,open(0).read().split())
if max(a)<k:
    print("IMPOSSIBLE")
elif max(a)==k:
    print("POSSIBLE")
else:
    if k%reduce(gcd,a)==0:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")