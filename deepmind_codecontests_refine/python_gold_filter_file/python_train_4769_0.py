from heapq import heappush, heappushpop

Q = int(input())

b = 0
la = []
sl = 0
ra = []
sr = 0

cnt = 0
for _ in range(Q):
    q = tuple(map(int, input().split()))
    # print(la, ra)
    if q[0] == 2:
        # 求値
        x = -la[0]
        cl = (cnt + 1) // 2
        cr = cnt - cl
        print(x, (cl * x - sl) + (sr - cr * x) + b)
    else:
        # 更新
        b += q[2]
        cnt += 1
        if cnt % 2 == 1:
            sr += q[1]
            x = heappushpop(ra, q[1])
            sr -= x
            sl += x
            heappush(la, -x)
        else:
            sl += q[1]
            x = heappushpop(la, -q[1])
            x *= -1
            sl -= x
            sr += x
            heappush(ra, x)
