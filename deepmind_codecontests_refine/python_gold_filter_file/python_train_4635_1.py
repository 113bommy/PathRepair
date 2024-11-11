n,m=map(int,input().split())
a=[]
for i in range(n):
    s=input()
    tmp=list(s)
    a.append(tmp)
right=[]
up=[]
for i in range(n):
    tmp1=[]
    tmp2=[]
    for j in range(m):
        tmp1.append(0)
        tmp2.append(0)
    right.append(tmp1)
    up.append(tmp2)
for i in range(1,m):
    if a[0][i]=="#":
        right[0][i]=right[0][i-1]
    else:
        if a[0][i-1]==".":
            right[0][i]=1+right[0][i-1]
        else:
            right[0][i] = right[0][i - 1]
for i in range(1,n):
    if a[i][0]=="#":
        up[i][0]=up[i-1][0]
    else:
        if a[i-1][0]==".":
            up[i][0]=1+up[i-1][0]
        else:
            up[i][0] = up[i - 1][0]
for i in range(1,n):
    for j in range(1,m):
        if a[i][j]=="#":
            right[i][j]=right[i-1][j]+right[i][j-1]-right[i-1][j-1]
            up[i][j]=up[i-1][j]+up[i][j-1]-up[i-1][j-1]
        else:
            if a[i][j-1]==".":
                right[i][j]=1+right[i-1][j]+right[i][j-1]-right[i-1][j-1]
            else:
                right[i][j] = right[i - 1][j] + right[i][j - 1] - right[i - 1][j - 1]
            if a[i-1][j]==".":
                up[i][j]=up[i-1][j]+up[i][j-1]-up[i-1][j-1]+1
            else:
                up[i][j] = up[i - 1][j] + up[i][j - 1] - up[i - 1][j - 1]
q=int(input())
for _ in range(q):
    i1,j1,i2,j2=map(int,input().split())
    i1-=1
    j1-=1
    i2-=1
    j2-=1
    if i1>0:
        ans=right[i2][j2]-right[i2][j1]-right[i1-1][j2]+right[i1-1][j1]
    else:
        ans = right[i2][j2] - right[i2][j1]
    if j1>0:
        ans+=up[i2][j2]-up[i2][j1-1]-up[i1][j2]+up[i1][j1-1]
    else:
        ans += up[i2][j2] - up[i1][j2]
    print(ans)