N,K = map(int,input().split())
A = list(map(int,input().split()))
g = A[0]
import fractions
for i in range(1,N):
    g = fractions.gcd(g,A[i])
if K % g == 0:
    if K <= max(A):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')
else:
    print('IMPOSSIBLE')