
import heapq as hq

Q = int(input())



low = []
high = []

_,mid,val = map(int,input().split())

for _ in range(Q-1):
    s = input()
    if s[0] == '1':
        _,a,b = map(int,s.split())
        if mid is None:
            if a < -low[0]:
                mid = -hq.heapreplace(low, -a)
            elif a > high[0]:
                mid = hq.heapreplace(high, a)
            else:
                mid = a
            val += abs(mid-a)+b
        else:
            val += abs(mid-a)+b
            x,y = sorted((a,mid))
            hq.heappush(high, y)
            hq.heappush(low, -x)
            mid = None

    else:
        print(-low[0] if mid is None else mid, val)