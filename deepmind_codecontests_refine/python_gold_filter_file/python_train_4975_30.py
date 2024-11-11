import sys
sys.setrecursionlimit(10 ** 6)


def dfs(v, step):
    global node0, node1
    if step & 1:
        color[v] = 1
        node1 += 1
    else:
        color[v] = 0
        node0 += 1
    for nv in edge[v]:
        if color[nv] is None:
            dfs(nv, step + 1)


N = int(input())
edge = [[] for _ in range(N)]
for s in sys.stdin.readlines():
    a, b = map(int, s.split())
    a -= 1; b -= 1
    edge[a].append(b)
    edge[b].append(a)
color = [None] * N
node0 = node1 = 0
dfs(0, 0)

ans = [None] * N
num0 = N // 3
num1 = N // 3 + (N % 3 >= 1)
num2 = N // 3 + (N % 3 == 2)
if node0 > num0 and node1 > num0:
    cur = 0
    while num1 > 0:
        if color[cur] == 1:
            ans[cur] = 3 * num1 - 2
            num1 -= 1
        cur += 1
    cur = 0
    while num2 > 0:
        if color[cur] == 0:
            ans[cur] = 3 * num2 - 1
            num2 -= 1
        cur += 1
elif node0 <= num0:
    cur = 0
    while node0 > 0:
        if color[cur] == 0:
            ans[cur] = 3 * num0
            num0 -= 1
            node0 -= 1
        cur += 1
else:
    cur = 0
    while node1 > 0:
        if color[cur] == 1:
            ans[cur] = 3 * num0
            num0 -= 1
            node1 -= 1
        cur += 1

cur = 0
while num0 > 0:
    if ans[cur] is None:
        ans[cur] = 3 * num0
        num0 -= 1
    cur += 1
while num1 > 0:
    if ans[cur] is None:
        ans[cur] = 3 * num1 - 2
        num1 -= 1
    cur += 1
while num2 > 0:
    if ans[cur] is None:
        ans[cur] = 3 * num2 - 1
        num2 -= 1
    cur += 1


print(*ans)
