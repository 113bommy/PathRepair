import heapq
N, K = map(int,input().split())
L1 = []
L2 = []
S = set()
val = 0

for _ in range(N):
    t, d = map(int,input().split())
    L1.append((d, t))

L1.sort(reverse = True)

for i in range(K):
    val += L1[i][0]
    if L1[i][1] in S:
        heapq.heappush(L2, L1[i][0])
    else:
        S.add(L1[i][1])

ans = val + len(S) ** 2

for i in range(K, N):
    if len(L2) == 0:
        break
    if not L1[i][1] in S:
        S.add(L1[i][1])
        val -= heapq.heappop(L2)
        val += L1[i][0]
        ans = max(ans, val + len(S) ** 2)

print(ans)