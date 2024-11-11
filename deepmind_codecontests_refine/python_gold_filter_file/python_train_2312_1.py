
def solve():
    n = int(input())
    a,lim = list(map(int,input().split(' '))), n//2
    wt,vt = [],[]
    pt = -1;
    for v in a:
        if v != pt:
            pt = v
            wt.append(0)
            vt.append(v)
        wt[-1] += 1

    g,s,b = wt[0],0,0
    c = 1;
    while s <= g and s < lim - g and c < len(wt):
        s += wt[c]
        c += 1
    while b <= lim - s - g and c < len(wt):
        b += wt[c]
        c += 1
    b -= wt[c - 1]
    if min(g,s,b) <= 0 or g >= s or g >= b:
        print(0,0,0)
    else:
        print(g,s,b)
n = int(input())
for i in range(n):
    solve()
