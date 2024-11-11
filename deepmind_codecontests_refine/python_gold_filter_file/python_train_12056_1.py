from functools import lru_cache
 
N = int(input())
A = list(map(int, input().split()))
 
@lru_cache(None)
def f(l, r, xl, xr):
  if l+1 == r:
    return xl * A[l] + xr * A[r]
  tmp = float("inf")
  for m in range(l+1, r):
    v = f(l, m, xl, xl+xr) + f(m, r, xl+xr, xr) - (xl+xr) * A[m]
    tmp = min(tmp, v)
  return tmp
 
print(f(0, N-1, 1, 1))