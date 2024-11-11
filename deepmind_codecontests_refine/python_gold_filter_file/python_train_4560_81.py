N,K = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))
A.sort()
F.sort(reverse=True)

ng = -1
ok = 10**18
while ok - ng > 1:
    mid = (ok + ng) // 2
    c = 0
    for i in range(N):
        c += max(0,A[i]-mid//F[i])
    if c <= K:
        ok = mid
    else:
        ng = mid
print(ok)
