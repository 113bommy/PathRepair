N, K = map(int,input().split())
A = [0]+list(map(int,input().split()))

p = A[1]
for i in range(K+1,N+1):
    print(["No","Yes"][p < A[i]])
    p = A[i-K+1]
