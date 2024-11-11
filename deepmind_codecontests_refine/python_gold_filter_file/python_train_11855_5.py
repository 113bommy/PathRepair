n, m = map(int, input().split())
N = [1]*n
P = [True] + [False]*(n-1)
for i in range(m):
    x, y = list(map(lambda tmp: tmp-1, map(int, input().split())))
    P[y] = True if P[x]==True else P[y]
    N[x] -= 1
    N[y] += 1
    P[x] = False if N[x]==0 else P[x]
print(sum(P))