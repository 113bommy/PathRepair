import sys
N, C, K = map(int, input().split())
A = list(map(int, sys.stdin.readlines()))+[10**10]
A.sort()
a, c, t = 0, 1, A[0]+K
for i in A[1:]:
    if i <= t and c < C:
        c += 1
    else:
        t, c = i + K, 1
        a += 1
 
print(a)