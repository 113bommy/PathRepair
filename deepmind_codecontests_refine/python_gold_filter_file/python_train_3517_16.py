from collections import defaultdict, deque, Counter
N,M,K= map(int,input().split())

friend = defaultdict(list)
#block = defaultdict(list)

for i in range(M):
    a,b= list(map(int,input().split()))
    friend[a].append(b)
    friend[b].append(a)
'''
for i in range(K):
    c,d= list(map(int,input().split()))
    block[c].append(d)
    block[d].append(c)
    '''
block = [list(map(int,input().split())) for i in range(K)]

IDs = [-1] * (N+1)
ID = 0
for i in range(1,N+1):
    if IDs[i] != -1:
        continue
    dq = deque([i])
    while dq:
        v = dq.popleft()
        IDs[v] = ID
        for nv in friend[v]:
            if IDs[nv] == -1:
                dq.append(nv)
    ID += 1

group = Counter(IDs)

ans = []
for i in range(1,N+1):
    temp = group[IDs[i]] - len(friend[i]) - 1
    ans.append(temp)

for c,d in block:
    if IDs[c] == IDs[d]:
        ans[c-1] -= 1
        ans[d-1] -= 1

print(*ans)







