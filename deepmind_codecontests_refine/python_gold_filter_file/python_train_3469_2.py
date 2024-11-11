test=int(input())
def dfs(c,m,p,v,l):
    res=(p/r)*l
    if c>0:
        if c>v:
            if m>0:
                res+=(c/r)*dfs(c-v,m+v/2,p+v/2,v,l+1)
            else:
                res+=(c/r)*dfs(c-v,0,p+v,v,l+1)
        else:
            if m>0:
                res+=(c/r)*dfs(0,m+c/2,p+c/2,v,l+1)
            else:
                res+=(c/r)*dfs(0,0,p+c,v,l+1)
    if m>0:
        if m>v:
            if c>0:
                res+=(m/r)*dfs(c+v/2,m-v,p+v/2,v,l+1)
            else:
                res+=(m/r)*dfs(0,m-v,p+v,v,l+1)
        else:
            if c>0:
                res+=(m/r)*dfs(c+m/2,0,p+m/2,v,l+1)
            else:
                res+=(m/r)*dfs(0,0,p+m,v,l+1)

    return res
for _ in range(test):
    c,m,p,v=map(float,input().split())
    r=10**6
    val=dfs(c*r,m*r,p*r,v*r,1)
    val="{0:.6f}".format(val)
    print(val)