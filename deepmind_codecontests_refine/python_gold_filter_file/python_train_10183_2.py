ri = lambda: int(input())
rl = lambda: list(map(int,input().split()))

N,K=rl()
td = [rl() for _ in range(N)]

from operator import itemgetter
key0 = itemgetter(0)
key1 = itemgetter(1)
td.sort(key=key1,reverse=True)

netas = set()
dup = []

for t,d in td[:K]:
    if t in netas:
        dup.append(d)
    else:
        netas.add(t)

score = len(netas)**2 + sum(map(key1,td[:K]))
ans = score
for t,d in td[K:]:
    if t not in netas and dup != []:
        netas.add(t)
        dup_ = dup.pop(-1)
        score += 2*len(netas)-1 + d - dup_
        ans = max(ans,score)
print(ans)