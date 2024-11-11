from functools import reduce
from itertools import combinations

N,MOD = map(int,input().split())
A = list(map(int,input().split()))

def solve(A,MOD):

    if len(A) > MOD:
        return 0
    return reduce(lambda x,y:(x*y)%MOD, (abs(a-b)%MOD for a,b in combinations(A,2)))

print(solve(A,MOD)%MOD)