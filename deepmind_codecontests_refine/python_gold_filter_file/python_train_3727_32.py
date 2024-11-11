import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

from heapq import heappop, heappush

N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

q = []
push = lambda x,i: heappush(q, (-x<<30)+i)
for i,x in enumerate(B):
    push(x,i)

answer = 0
mask = (1<<30)-1
while q:
    i = heappop(q)&mask
    x = B[i]
    dx = x-A[i]
    if dx < 0:
        answer = -1
        break
    if dx == 0:
        continue
    left = i-1 if i >= 1 else N-1
    right = i+1 if i < N-1 else 0
    nbd = B[left] + B[right]
    t = dx // nbd
    if t == 0:
        answer = -1
        break
    B[i] -= nbd * t
    answer += t
    push(B[i],i)

print(answer)