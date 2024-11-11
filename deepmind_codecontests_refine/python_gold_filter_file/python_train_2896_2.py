def getmaxand(bs, K):
    for k in range(40, -1, -1):
        bit = 1 << k
        avails = [v for v in bs if v & bit]
        if len(avails) < K:
            continue
        filt = ~(-1 << k)
        elims = [v & filt for v in avails]
        return (1 << k) + getmaxand(elims, K)
    return 0


N, K = map(int, input().split())
A = [int(s) for s in input().split()]

bs = []
for l in range(N):
    for r in range(l, N):
        bs.append(sum(A[l:r+1]))

print(getmaxand(bs, K))
