import sys
from collections import deque

input = sys.stdin.readline
n, u, v = map(int, input().split())

E = [[] for i in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    E[a-1].append(b-1)
    E[b-1].append(a-1)

memo = [[0, 0] for i in range(n)]

def dfs(cur, pre, p):
    stack = deque([[cur, pre]])
    while stack:
        cur, pre = stack.pop()
        if pre != -1:
            memo[cur][p] = memo[pre][p] + 1
        for e in E[cur]:
            if e != pre:
                stack.append([e, cur])

dfs(u - 1, - 1, 0)
dfs(v - 1, -1, 1)

# print(memo)
ans = 0
for a, b in memo:
    if a <= b:
        ans = max(ans, b - 1)
print(ans)
