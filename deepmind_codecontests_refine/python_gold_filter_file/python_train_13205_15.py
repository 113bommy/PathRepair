# D
N,A,B = map(int, input().split())
v = list(map(int, input().split()))
v.sort(reverse=True)

max_mean = sum(v[:A])/A
print(max_mean)

from collections import Counter
from math import factorial

def comb(n,r):
    return factorial(n)//(factorial(r)*factorial(n-r))

v_count = Counter(v)
ans = 0
if v[0]==v[A-1]:
    n = v_count[v[A-1]]
    for r in range(A, B+1):
        if r>n: break
        ans += comb(n, r)
else:
    #print(n, r)
    n = v_count[v[A-1]]
    select_count = Counter(v[:A])
    r = select_count[v[A-1]]
    ans = comb(n,r)
print(ans)