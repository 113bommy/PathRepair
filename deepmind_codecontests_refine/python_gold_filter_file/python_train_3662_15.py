from itertools import accumulate
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))
A = sorted(A)
L = []
prev = -1
for a in A:
    if a == prev:
        L[-1] += 1
    else:
        L.append(1)
        prev = a


max_types = int(2**((8*K)//N))

all_types = len(L)
del_types = all_types-max_types
if del_types <= 0:
    ans = 0
else:
    ans = float('inf')
    sum_L = N
    L_acc = [0]+list(accumulate(L))
    for i in range(len(L)-max_types):
        s = L_acc[i+max_types]-L_acc[i]
        ans = min(ans, sum_L-s)
print(ans)
