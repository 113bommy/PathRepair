N = int(input())
for i in range(N):
    n,k = map(int,input().split())
    L = list(map(int,input().split()))
    if n <= k:
        print(0)
    else:
        A = []
        for j in range(1,n):
            A.append(L[j]-L[j-1])
        A.sort()
        A.reverse()
        S = L[n-1]-L[0]
        for l in range(k-1):
            S -= A[l]
        print(S)
