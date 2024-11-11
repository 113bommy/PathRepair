import sys
import itertools

N = int(input())
A = list(input().split())
A = [int(A[i]) for i in range(N+1)]
MAX = [1 for i in range(N+1)]
A_inter = list(reversed(list(itertools.accumulate(reversed(A)))))

for i in range(N+1):
    if A[i] > MAX[i]:
        print(-1)
        sys.exit()
    elif i != N:
        MAX[i+1] = (MAX[i] - A[i]) * 2
        
print(sum([min(MAX[i], A_inter[i]) for i in range(N+1)]))