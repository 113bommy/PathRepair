import math
import bisect
import collections

N = int(input())
A = list(map(int,input().split()))
C = collections.Counter(A)
A = sorted(list(C.keys()))
#print(C)
#print(A)

ans = 0
for i in range(len(A)-1,-1,-1):
  a = A[i]
  b = (1<<(int(math.log(a,2))+1))-a
  if a == b:
    ans += C[a]//2
    C[a] -= C[a]//2*2
  else:
    r = bisect.bisect_left(A, b)
    if r < i and A[r] == b:
      mn = min(C[a],C[A[r]])
      ans += mn
      C[a] -=  mn
      C[A[r]] -= mn
print(ans)
