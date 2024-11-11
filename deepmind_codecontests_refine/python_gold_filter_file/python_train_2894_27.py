N, Q = map(int, input().split())
d = [0 for i in range(N)]

for i in range(N-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    d[b] = a
ans = [0 for i in range(N)]

for i in range(Q):
    p, x = map(int, input().split())
    p -= 1
    ans[p] += x

for i in range(1, N):
    ans[i] += ans[d[i]]

print(*ans)