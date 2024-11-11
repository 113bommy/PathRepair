t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    g=[]
    for i in range(n):
        g.append(list(map(int,input().split())))
    d=[]
    for i in range(n):
        d.append([0]*m)
    for i in range(n):
        for j in range(m):
            if not (i==0 and j==0):
                if i==0:
                    d[i][j]=d[i][j-1]+1
                else:
                    d[i][j]=d[i-1][j]+1
    ans=0
    for k in range(n+m-1):
        c1,c0=0,0
        for i in range(n):
            for j in range(m):
                if (d[i][j]==k or d[i][j]==n+m-2-k) and k!=n+m-2-k:
                    if g[i][j]==1:
                        c1+=1
                    else:
                        c0+=1
        ans=ans+min(c1,c0)
    print(ans//2)