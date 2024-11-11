import sys
input = sys.stdin.readline
from heapq import heappop, heappush
N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
q = []
for i,b in enumerate(B):
    heappush(q,(-b,i))
answer = 0
while len(q)>0:
    b,i = heappop(q)
    b = -b
    if b < A[i]:
        answer = -1
        break
    sub = B[(i-1)%N] + B[(i+1)%N]
    t = ( b - A[i]) // sub
    if t == 0:
        if b == A[i]:
            continue
        answer = -1
        break
    B[i] -= sub * t
    answer += t
    heappush(q,(-B[i],i))
print(answer)

