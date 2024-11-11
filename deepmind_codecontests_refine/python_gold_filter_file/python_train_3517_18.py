from collections import deque,Counter

n,m,k = map(int,input().split())
frd = [[] for _ in range(n)]
blk = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    frd[a].append(b)
    frd[b].append(a)
for _ in range(k):
    c,d = map(int,input().split())
    c -= 1
    d -= 1
    blk[c].append(d)
    blk[d].append(c)

ucnt = 0
uni = [-1]*n
stk = deque()
for i in range(n):
    if uni[i] != -1: continue
    stk.append((i,-1))
    while stk:
        cur,prev = stk.pop()
        uni[cur] = ucnt
        for nxt in frd[cur]:
            if nxt == prev: continue
            if uni[nxt] != -1: continue
            stk.append((nxt,cur))
    ucnt += 1
cnt = Counter(uni)

for i in range(n):
    ans = cnt[uni[i]] - 1
    for f in frd[i]:
        if uni[i] == uni[f]: ans -= 1
    for b in blk[i]:
        if uni[i] == uni[b]: ans -= 1
    print(ans,end=" ")