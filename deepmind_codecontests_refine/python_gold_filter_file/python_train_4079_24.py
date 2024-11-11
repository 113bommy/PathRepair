t = int(input())
for _ in range(t):
    n = int(input())
    ymx = 10**5
    ymn = -ymx
    xmx = ymx
    xmn = ymn
    for _ in range(n):
        x, y, a, b, c, d = map(int, input().split())
        # aはxの負 , cはxの正
        if a==0:
            xmn = max(xmn,x)
        if c==0:
            xmx = min(xmx,x)
        # bはyの負 , dはyの正
        if d==0:
            ymn = max(ymn,y)
        if b==0:
            ymx = min(ymx,y)
    if xmx>=xmn and ymx>=ymn:
        print(1,xmn,ymn)
    else:
        print(0)
