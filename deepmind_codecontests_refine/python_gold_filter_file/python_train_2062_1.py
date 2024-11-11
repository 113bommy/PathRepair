import sys
sys.setrecursionlimit(10000000)

def visit_tree(now, num):
    visited[now] = num
    for i in range(len(tree[now])):
        if not visited[tree[now][i]]:
            visit_tree(tree[now][i], num)

n, m = map(int, input().split())
tree = [[] for _ in range(n)]
for i in range(m):
    x, y, z = map(int, input().split())
    tree[x - 1].append(y - 1)
    tree[y - 1].append(x - 1)

visited = [0 for _ in range(n)]
num = 0
for i in range(n):
    if not visited[i]:
        num += 1
        visit_tree(i, num)

print(num)