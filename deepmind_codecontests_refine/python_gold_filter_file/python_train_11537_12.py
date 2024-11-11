a,b,q = map(int,input().split())
s = [-float('inf')]+[int(input()) for i in range(a)]+[float('inf')]
t = [-float('inf')]+[int(input()) for i in range(b)]+[float('inf')]
x = [int(input()) for i in range(q)]
import bisect
for x_ in x:
    s_r = bisect.bisect_right(s,x_)
    t_r = bisect.bisect_right(t,x_)
    res = float('inf')
    for S in [s[s_r-1],s[s_r]]:
        for T in [t[t_r-1],t[t_r]]:
            d1 = abs(S-x_)+abs(T-S)
            d2 = abs(T-x_)+abs(S-T)
            res = min(res,d1,d2)
    print(res)