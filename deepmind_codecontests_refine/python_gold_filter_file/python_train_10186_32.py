from itertools import permutations

n, m, r = map(int, input().split())
A = list(map(int, input().split()))
d = [[1e18]*n for i in range(n)]
for i in range(m):
        a, b, c = map(int, input().split())
        d[a-1][b-1] = d[b-1][a-1] = c

for k in range(n):
        for i in range(n):
                for j in range(n):
                        d[i][j] = min(d[i][j], d[i][k]+d[k][j])


ans = 1e18
for x in permutations(A):
        l = 0
        for i in range(r-1):
                l += d[x[i]-1][x[i+1]-1]
        ans = min(ans, l)
print(ans)