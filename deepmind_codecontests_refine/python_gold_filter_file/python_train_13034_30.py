import sys
input = sys.stdin.readline

Q = int(input())
Query = []
for _ in range(Q):
    N = int(input())
    A = list(map(int, input().split()))
    Query.append((N, A))

for N, A in Query:
    x = 0
    s = 0
    for a in A:
        x ^= a
        s += a
    
    t = (s % 2) + (1<<50)
    s += t
    x ^= t
    d = (2*x - s)//2
    print(3)
    print(t, d, d)