import sys
input = sys.stdin.readline
from collections import deque, defaultdict
from heapq import heappush, heappop
n, k = map(int, input().split())
A = list(map(int, input().split()))
dic = defaultdict(deque)
for i, a in enumerate(A):
    dic[a].append(i)
hp = []
# for d in dic:
#     heappush(hp, (-dic[d][0], d))
S = set()
ans = 0
for i, a in enumerate(A):
    dic[a].popleft()

    if a not in S:
        if len(S) < k:
            S.add(a)
            ans += 1
        else:
            idx = heappop(hp)[1]
            S.discard(idx)
            S.add(a)
            ans += 1

    if dic[a]: heappush(hp, (-dic[a][0], a))
    else: heappush(hp, (float("-inf"), a))
print(ans)