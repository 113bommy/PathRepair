import sys
input = sys.stdin.readline

Q = int(input())
Query = []
for _ in range(Q):
    N = int(input())
    A = list(map(int, input().split()))
    Query.append((N, A))

for N, A in Query:
    c = 0
    m = 10**16
    for i in reversed(range(N)):
        if A[i] <= m:
            c += 1
        m = min(m, A[i])
    print(N-c)