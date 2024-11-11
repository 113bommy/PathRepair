N,K = map(int,input().split())
V = list(map(int,input().split()))
KK = K
K = min(N,K)

ans = 0
for k in range(1,K+1):
    for i in range(k+1):
        R = V[-(k-i):]
        if len(R) == N:
            R = []
        # print(R)
        L = V[:i]+R+[0]
        L.sort()
        zero_index = min(L.index(0),KK-k)
        res = sum(L[zero_index:])
        ans = max(ans,res)
print(ans)