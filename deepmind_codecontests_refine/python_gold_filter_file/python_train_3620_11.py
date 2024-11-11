from bisect import bisect_left
from collections import defaultdict

n = int(input())

xysame, upright, downright = {},{},{}
u_list = ("U","R","D","L")
for u in u_list:
    xysame[u] = defaultdict(list)
    upright[u] = defaultdict(list)
    downright[u] = defaultdict(list)

for _ in range(n):
    x,y,u = input().split()
    x,y = int(x),int(y)
    if u == "U" or u == "D":
        xysame[u][x].append(y)
    else:
        xysame[u][y].append(x)
    upright[u][y-x].append(x)
    downright[u][y+x].append(x)
    
for u in u_list:
    for key in xysame[u].keys():
        xysame[u][key].sort()
    for key in upright[u].keys():
        upright[u][key].sort()
    for key in downright[u].keys():
        downright[u][key].sort()

INF = 10**6
ans = INF


def line(low,high,type_ = 1):
    ret = INF
    for k,v in low.items():
        if high[k] == []: continue

        for vi in v:
            index = bisect_left(high[k], vi)
            if index == len(high[k]): continue
            ret = min(ret,(high[k][index]-vi)/type_)
    return ret

ans = min(ans, line(xysame["U"],xysame["D"],2))
ans = min(ans, line(xysame["R"],xysame["L"],2))
ans = min(ans, line(upright["R"],upright["D"],1))
ans = min(ans, line(upright["U"],upright["L"],1))
ans = min(ans, line(downright["R"],downright["U"],1))
ans = min(ans, line(downright["D"],downright["L"],1))

ans = int(ans*10)
if ans ==INF*10: ans = "SAFE"
    
print(ans)