N, M = map(int, input().split())
A = []
B = []
for _ in range(M):
    a, b = map(int,  input().split())
    A.append(a)
    B.append(b)
ans = []
ans.append(N * (N - 1) / 2)

n = [-1 for i in range(N)]

def find(x):
    if n[x] < 0:
        return x
    n[x] = find(n[x])
    return n[x]

def size(x):
    return -n[find(x)]

def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return 0
    if size(x) < size(y):
        x, y = y, x
    n[x] += n[y]
    n[y] = x
    return 1

for i in range(1, M):
    sab = size(A[-i] - 1) * size(B[-i] - 1)
    if unite(A[-i] - 1, B[-i] - 1) == 0:
        ans.append(ans[i - 1])
    else:
        ans.append(ans[i - 1] - sab)
for i in range(1, M + 1):
    print(int(ans[-i]))
