N, K = map(int,input().split())
A = list(map(int,input().split()))

for i in range(K, N):
    print('Yes') if A[i - K] < A[i] else print('No')