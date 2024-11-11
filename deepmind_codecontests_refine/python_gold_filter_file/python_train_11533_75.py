from collections import deque

H, W = map(int, input().split())
C = tuple(map(lambda a: int(a) - 1, input().split()))
D = tuple(map(lambda a: int(a) - 1, input().split()))
S = [input() for _ in range(H)]
INF = 10**18

def cord(h, w):
    return h * W + w

minDist = [INF] * (H * W + 10)
que = deque([(C, 0)])
minDist[cord(*C)] = 0

while que:
    (h, w), dist = que.popleft()

    for dh in range(-2, 3):
        for dw in range(-2, 3):
            toH, toW = h + dh, w + dw
            if not (0 <= toH < H and 0 <= toW < W) or (h, w) == (toH, toW):
                continue
            if S[toH][toW] == '#':
                continue

            d = 0 if (abs(dh) + abs(dw) <= 1) else 1
            if minDist[cord(toH, toW)] > dist + d:
                minDist[cord(toH, toW)] = dist + d
                if d == 0: que.appendleft(((toH, toW), dist + d))
                else: que.append(((toH, toW), dist + d))

print(minDist[cord(*D)] if minDist[cord(*D)] < INF else -1)
