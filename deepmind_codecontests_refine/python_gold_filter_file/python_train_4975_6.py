import sys
sys.setrecursionlimit(700000)

def s_in():
    return input()

def n_in():
    return int(input())

def l_in():
    return list(map(int, input().split()))

def print_l(l):
    print(' '.join(map(str, l)))

class Interval():
    def __init__(self, li):
        self.li = li
        self.n = len(li)
        self.sum_li = [li[0]]
        for i in range(1, self.n):
            self.sum_li.append(self.sum_li[i-1] + li[i])

    def sum(self, a, b=None):
        if b is None:
            return self.sum(0, a)

        res = self.sum_li[min(self.n-1, b-1)]
        if a > 0:
            res -= self.sum_li[a-1]
        return res

N = n_in()
edges = [[] for _ in range(N)]

for _ in range(N-1):
    a,b = l_in()
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)


# Euler Tour の構築
S = []
depth = [0]*N
visited = set()

def dfs(v, d):
    visited.add(v)
    depth[v] = d
    S.append(v)
    for w in edges[v]:
        if w in visited:
            continue
        dfs(w, d+1)
        S.append(v)


root = 0
dfs(root, 0)

res = [0 for _ in range(N)]

from collections import deque
q0 = deque(i for i in range(1,N+1) if i%3 == 0)
q1 = deque(i for i in range(1,N+1) if i%3 == 1)
q2 = deque(i for i in range(1,N+1) if i%3 == 2)

even_depth = len(list(filter(lambda d: d%2 == 0, depth)))
odd_depth = len(list(filter(lambda d: d%2 != 0, depth)))

if even_depth > N//3 and odd_depth > N//3:
    for i, d in enumerate(depth):
        if d%2 == 0:
            if len(q1) > 0:
                res[i] = q1.popleft()
            else:
                res[i] = q0.popleft()
        else:
            if len(q2) > 0:
                res[i] = q2.popleft()
            else:
                res[i] = q0.popleft()
elif even_depth <= N//3:
    for i, d in enumerate(depth):
        if d%2 == 0:
            res[i] = q0.popleft()
        else:
            if len(q1) > 0:
                res[i] = q1.popleft()
            elif len(q2) > 0:
                res[i] = q2.popleft()
            else:
                res[i] = q0.popleft()
else:
    for i, d in enumerate(depth):
        if d%2 != 0:
            res[i] = q0.popleft()
        else:
            if len(q1) > 0:
                res[i] = q1.popleft()
            elif len(q2) > 0:
                res[i] = q2.popleft()
            else:
                res[i] = q0.popleft()


print_l(res)
