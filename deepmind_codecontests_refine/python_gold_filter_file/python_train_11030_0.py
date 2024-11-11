import itertools
N,M = map(int,input().split())
src = [tuple(map(float,input().split())) for i in range(N)]
if M <= 1:
    print(0)
    exit()
dists = [[None for j in range(N)] for i in range(N)]
for i in range(N-1):
    for j in range(i+1,N):
        l1,a1,b1 = src[i]
        l2,a2,b2 = src[j]
        dist = 0
        dist += (l1-l2)**2 + (a1-a2)**2 + (b1-b2)**2
        dists[i][j] = dists[j][i] = dist

ans = 0
for ptn in list(itertools.combinations(range(N),M)):
    total = 0
    for i in range(M-1):
        for j in range(i+1,M):
            total += dists[ptn[i]][ptn[j]]
    ans = max(ans, total)
print(ans)