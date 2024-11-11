import itertools

N,M,R = map(int, input().split())
r = map(int, input().split())
l = [[1e9 for i in range(N+1)] for i in range(N+1)]

for i in range(M):
    a,b,c = map(int, input().split())
    l[a][b] = l[b][a] = c

for k in range(1,N+1):
    for i in range(1,N+1):
        for j in range(1,N+1):
            t = l[i][k] + l[k][j]
            if l[i][j] > t: l[i][j] = t

ans = 1e9
for a in itertools.permutations(r):
    s = 0
    for i,j in zip(a[:-1],a[1:]):
        s += l[i][j]
    if ans > s: ans = s

print(ans)
