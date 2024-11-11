import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque
N = int(input())
X = [[] for i in range(N)]
for i in range(N-1):
    x, y = map(int, input().split())
    X[x-1].append(y-1)
    X[y-1].append(x-1)

Y = [(-10**9, 10**9) for _ in range(N)]
K = int(input())
for _ in range(K):
    v, p = map(int, input().split())
    Y[v-1] = (p, p)

P = [-1] * N
Q = deque([0])
R = []
while Q:
    i = deque.popleft(Q)
    R.append(i)
    for a in X[i]:
        if a != P[i]:
            P[a] = i
            X[a].remove(i)
            deque.append(Q, a)


def calc():
    for i in R[::-1]:
        e, o = 0, 0
        l, r = Y[i]
        if r != 10 ** 9:
            if l % 2:
                o = 1
            else:
                e = 1
        for j in X[i]:
            a, b = Y[j]
            if b == 10**9: continue
            if a % 2:
                e = 1
            else:
                o = 1
            l = max(l, a - 1)
            r = min(r, b + 1)
        if (e and o) or (l > r):
            print("No")
            return 0
        elif e or o:
            Y[i] = (l, r)
    
    for i in R[1:]:
        if Y[P[i]][0] - 1 >= Y[i][0]:
            Y[i] = (Y[P[i]][0] - 1, 0)
        else:
            Y[i] = (Y[P[i]][0] + 1, 0)
    
    print("Yes")
    for i in range(N):
        print(Y[i][0])

calc()