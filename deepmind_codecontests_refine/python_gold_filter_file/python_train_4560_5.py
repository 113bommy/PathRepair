N, K = map(int, input().split())
A = [int(i) for i in input().split()]
F = [int(i) for i in input().split()]

A.sort(reverse=True)
F.sort()

ng = -1
ok = 10**12
while ok - ng > 1 :
    mid = (ok + ng) // 2
    k = 0
    for i in range(N) :
        k += max(0, A[i] - mid // F[i])
    if k <= K :
        ok = mid
    else :
        ng = mid
print(ok)