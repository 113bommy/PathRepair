A, B, K = map(int, input().split())

m  = min(A+K, B+1)
for i in range(A, m):
    print(i)
n = max(A+K, B-K+1)
for j in range(n, B+1):
    print(j)