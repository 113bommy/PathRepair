import sys
sys.setrecursionlimit(10 ** 9)

N, M = map(int, input().split())

tree = [-1] * N

def root(x):
  if tree[x] < 0:
    return x
  else:
    tree[x] = root(tree[x])
    return tree[x]

def unite(x, y):
  rx, ry = root(x), root(y)
  if rx == ry: return
  tree[rx] += tree[ry]
  tree[ry] = rx

def size(x):
  return -tree[root(x)]

for i in range(M):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  unite(a, b)

print(max(map(size, range(N))))
