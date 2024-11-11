t = int(input())

for _ in range(t):
    x,y = map(int,input().split())
    cost = list(map(int,input().split()))
    truecost = [0]*6
    for i in range(6):
        truecost[i] = min(cost[i],cost[(i-1)%6]+cost[(i+1)%6])
    # print(truecost)
    ans = 0
    if x > 0 and y > 0:
        w = min(x,y)
        ans += w*truecost[0]
        x -= w
        y -= w
    if x < 0 and y < 0:
        w = min(-x,-y)
        ans += w*truecost[3]
        x += w
        y += w
    if x < 0:
        ans += (-x)*truecost[2]
        x = 0
    if y < 0:
        ans += (-y)*truecost[4]
        y = 0
    if x > 0:
        ans += x*truecost[5]
        x = 0
    if y > 0:
        ans += y*truecost[1]
    print(ans)