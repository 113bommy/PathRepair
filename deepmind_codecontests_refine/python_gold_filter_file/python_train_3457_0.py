from sys import stdin, stdout
from collections import namedtuple, deque
from bisect import insort

Castle = namedtuple("Castle", ['defense','recruit','importance'])

n,m,k = map(int, stdin.readline().split())
castles = []
portals = {}
for i in range(n):
    a,b,c = map(int, stdin.readline().split())
    castles.append(Castle(a,b,c))
    portals[i] = -1
for _ in range(m):
    u,v = map(int,stdin.readline().split())
    if u > v and u-1 > portals[v-1]:
        portals[v-1] = u-1

defending = deque()
pending = deque()
score = 0
for i,c in enumerate(castles):
    while k < c.defense and defending:
        v = defending.popleft()
        score -= v
        k+=1
    if k < c.defense:
        score = -1
        break
    k += c.recruit
    while pending and pending[0][0] == i:
        _,v = pending.popleft()
        k-=1
        score += v
        insort(defending, v)
    if portals[i] < 0:
        k-=1
        insort(defending, c.importance)
        score += c.importance
    else:
        insort(pending, (portals[i], c.importance))
else:
    while k < 0:
        v = defending.popleft()
        k+=1
        score-=v

stdout.write("{}\n".format(score))
