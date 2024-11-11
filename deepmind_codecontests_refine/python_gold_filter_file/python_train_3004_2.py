# F
from collections import deque
 
TT_list = []
# input
N, L = map(int, input().split())
T = 0.0
vt_now = 0.0
v_now = 0
que = deque()

for i in range(N):
    ti, v = map(int, input().split())
    t = float(ti)
    v_now += v
    vt_now += v*t
    # add
    if v == L:
        que.append([t, v])
    else:
        while v < L and len(que) > 0:
            t_, v_ = que[-1]
            if t_ <= t:
                que.append([t, v])
                break
            elif v + v_ >= L:
                v_ = v + v_ - L
                t = ((L - v) * t_ + v * t) / L
                v = L
                que = deque([[t, v]])
                v_now = L
                vt_now = t*L
                # break
            else:
                t = (t*v + t_*v_) / (v + v_)
                v = v + v_
                que.pop()
    # minus
    while v_now > L:
        if que[0][1] <= v_now - L:
            v_now -= que[0][1]
            vt_now -= que[0][1]*que[0][0]
            que.popleft()
        else:
            que[0][1] -= v_now - L
            vt_now -= (v_now - L)*que[0][0]
            v_now = L
            
    TT_list.append(vt_now / L)

for i in range(N):
    print(TT_list[i])
