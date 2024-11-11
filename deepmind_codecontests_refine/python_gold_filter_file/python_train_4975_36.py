import sys
input = sys.stdin.readline
from collections import deque
n = int(input())
E = [[] for i in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    E[a-1].append(b-1)
    E[b-1].append(a-1)

mod = [3, 1, 2]
ans = [0 for i in range(n)]
count = [0, 0]

def bfs(cur, pre, c):
    stack = deque([[cur, pre, c]])
    while stack:
        cur, pre, c = stack.popleft()
        count[c % 2] += 1
        for e in E[cur]:
            if e != pre:
                stack.append([e, cur, c+1])

def case1(cur, pre, c, i):
    stack = deque([[cur, pre, c]])
    while stack:
        cur, pre, c = stack.popleft()
        t = c % 2
        if t == i:
            ans[cur] = mod[0]
            mod[0] += 3
        else:
            if mod[1] <= n:
                ans[cur] = mod[1]
                mod[1] += 3
            elif mod[2] <= n:
                ans[cur] = mod[2]
                mod[2] += 3
            else:
                ans[cur] = mod[0]
                mod[0] += 3
        for e in E[cur]:
            if e != pre:
                stack.append([e, cur, c+1])

def case2(cur, pre, c):
    stack = deque([[cur, pre, c]])
    while stack:
        cur, pre, c = stack.popleft()
        t = c % 2
        if mod[t+1] <= n:
            ans[cur] = mod[t+1]
            mod[t+1] += 3
        else:
            ans[cur] = mod[0]
            mod[0] += 3
        for e in E[cur]:
            if e != pre:
                stack.append([e, cur, c+1])

bfs(0, -1, 0)

if count[0] <= n // 3:
    case1(0, -1, 0, 0)
elif count[1] <= n  // 3:
    case1(0, -1, 0, 1)
else:
    case2(0, -1, 0)

print(" ".join([str(i) for i in ans]))
