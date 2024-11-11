for _ in range(int(input())):
    n,m=map(int,input().split())
    s=[input() for _ in range(n)]
    for i in range(m):
        v=0
        for l in range(26):
            p=s[0][:i]+chr(97+l)+s[0][i+1:]
            t=0
            for u in s:
                r=0
                for h in range(m):
                    if u[h]!=p[h]:
                        if r:t=1;break
                        else:r=1
                if t:break
            else:print(p);v=1;break
        if v:break
    else:print(-1)