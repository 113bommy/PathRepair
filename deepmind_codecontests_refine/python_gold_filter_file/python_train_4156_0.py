# -*- coding: utf-8 -*-
from math import sqrt
from collections import deque

def inpl(): return list(map(int, input().split()))
W, H = inpl()
while H:
    G = []
    for h in range(H):
        tmp = []
        for w, x in enumerate(inpl()):
            tmp.append(x==1)
            if x == 2:
                s = (h, w)
            if x == 3:
                g = (h, w)
        G.append(tmp)

    Q = deque()
    Q.append([s, 0, []])
    found = False
    while Q:
        s, turn, deleated = Q.popleft()
        for h, w in deleated:
            G[h][w] = False
        for dh, dw in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
            if found:
                break
            h, w = s
            for step in range(30):
                nh, nw = h+dh, w+dw
                if not ((0 <= nh < H) & (0 <= nw < W)):
                    break
                if (nh, nw) == g:
                    print(turn+1)
                    found = True
                    break
                elif G[nh][nw] == True:
                    if turn != 9 and step > 0:
                        Q.append([(h, w), turn+1, deleated + [(nh, nw)]])
                    break
                h, w = nh, nw

        for h, w in deleated:
            G[h][w] = True
        if found:
            break
    else:
        print(-1)
    W, H = inpl()

