import sys
sys.setrecursionlimit(10**7)

def dfs(v, u, d):
    if d % 2 == 0:
        even.append(v)
    else:
        odd.append(v)
    for i in g[v]:
        if i == u:
            continue
        dfs(i, v, d + 1)
    return

N = int(input())
g = [[] for _ in range(N)]
odd = []
even =[]
ans = [-1] * N
nums = [[], [], []]
for i in range(1, N + 1):
    nums[i % 3].append(i)
sanlst = []
for i in range(N - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

dfs(0, -1, 0)
zCnt = len(nums[0])

if len(even) <= zCnt:
    for node in even:
        ans[node] = nums[0].pop()
    rest = nums[0] + nums[1] + nums[2]
    for node in odd:
        ans[node] = rest.pop()
elif len(odd) <= zCnt:
    for node in odd:
        ans[node] = nums[0].pop()
    rest = nums[0] + nums[1] + nums[2]
    for node in even:
        ans[node] = rest.pop()
else:
    for i in nums[1]:
        ans[even.pop()] = i
    for i in nums[2]:
        ans[odd.pop()] = i
    rest = nums[0]
    for i in even:
        ans[i] = rest.pop()
    for i in odd:
        ans[i] = rest.pop()

print(*ans)