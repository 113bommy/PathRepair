H,W,N=map(int,input().split())
sr,sc=map(lambda x:int(x)-1,input().split())
S=input()
T=input()

tmove=[(0,-1),(0,1),(-1,0),(1,0)]
amove=[(0,1),(0,-1),(1,0),(-1,0)]
m=[('L','R'),('R','L'),('U','D'),('D','U')]
for i in range(4):
    nh,nw=sr,sc
    t,a=tmove[i],amove[i]
    for k in range(N):
        if S[k]==m[i][0]:
            nh,nw=nh+t[0],nw+t[1]
        if nh<0 or nw<0 or nh>=H or nw>=W:
            print('NO')
            exit()
        gh,gw=nh+a[0],nw+a[1]
        if T[k]==m[i][1]:
            if gh>=0 and gh<H and gw>=0 and gw<W:
                nh,nw=gh,gw
print('YES')