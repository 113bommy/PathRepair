import heapq
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())
songs = [list(map(int, input().split())) for _ in range(N)]

songs = sorted(songs, key=lambda x: x[1], reverse=True)

# print(songs)
ans = -float('inf')
S = []
tmpS = 0
for t, v in songs:
    if len(S) < K:
        heapq.heappush(S, t)
        tmpS += t
        minB = v
    else:
        # print(S)
        if S[0] <= t:
            tmpS = tmpS-S[0]+t
            heapq.heappop(S)
            heapq.heappush(S, t)
            minB = v
    #print("tmp->", minB*tmpS)
    ans = max(ans, minB*tmpS)
print(ans)
