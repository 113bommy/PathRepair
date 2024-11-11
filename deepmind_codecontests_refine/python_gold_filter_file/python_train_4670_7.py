N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for i in range(M):
    A, B = map(int, input().split())
    edge[A-1].append(B-1)
    edge[B-1].append(A-1)
S = set()
S.add(0)
S.add(edge[0][0])
now = 0
ans1 = [1]
while True:
    next_v = -1
    for v in edge[now]:
        if v not in S:
            next_v = v
    if next_v<0:
        break
    now = next_v
    S.add(now)
    ans1.append(now+1)
now = edge[0][0]
ans2 = [edge[0][0]+1]
while True:
    next_v = -1
    for v in edge[now]:
        if v not in S:
            next_v = v
    if next_v<0:
        break
    now = next_v
    S.add(now)
    ans2.append(now+1)
ans = ans1[::-1]+ans2
print(len(ans))
print(*ans)