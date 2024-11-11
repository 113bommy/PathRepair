N,K = map(int,input().split())
A = [int(i) for i in input().split()]
loop = min(41,K)
for _ in range(loop):
    B = [0]*N
    for n in range(N):
        l = max(0,n-A[n])
        r = min(N-1,n+A[n])
        B[l]+=1
        if r+1<N:
            B[r+1] -= 1
    for n in range(1,N):
        B[n] += B[n-1]
    A = [b for b in B]
print(*A)
