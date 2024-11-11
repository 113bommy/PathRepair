from itertools import accumulate
n, K = map(int,input().split())
A = list(map(int,input().split()))
b = [0 for _ in range(n+1)]

for _ in range(K):
    for i,a in enumerate(A):
        b[max(0, i-a)] += 1
        b[min(n, i+a+1)] -= 1

    ac = list(accumulate(b))
    A = ac[:-1]
    b = [0 for _ in range(n+1)]
    if sum(A) == n*n:
        break
    
print(*A)