from collections import deque
import copy, sys

input = sys.stdin.readline
n = int(input())
a = [deque(map(lambda x: int(x) - 1, input().split())) for _ in range(n)]
q = deque()
pre_q = deque()
day = 0

def check(p, q):
    if not len(a[p]):
        return
    o = a[p][0]
    if p == a[o][0]:
        if p > o: p, o = o, p
        if not (p, o) in q:
            q.append((p, o))

fin = []
for p in range(n):
    if not p in fin:
        o = a[p][0]
        if p == a[o][0]:
            q.append((p, o))
            fin += [p, o]

while q:
    day += 1
    pre_q = copy.copy(q)
    q.clear()
    for (p, o) in pre_q:
        a[p].popleft()
        a[o].popleft()
        check(p, q)
        check(o, q)

if all(map(len, a)):
    print(-1)
else:
    print(day)
