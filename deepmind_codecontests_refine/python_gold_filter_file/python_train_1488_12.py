import sys
input = sys.stdin.readline
from collections import defaultdict
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    d=defaultdict(list)
    for i in range(n):
        d[a[i]].append(i)
    x=[]
    for i in d:
        m=0
        for j in range(len(d[i])):
            if j==0:
                m=max(m,d[i][j]+1)
            if j==len(d[i])-1:
                m=max(m,n-d[i][j])
                m=max(m,d[i][j]-d[i][j-1])
            else:
                m=max(m,d[i][j]-d[i][j-1])
        x.append([m,i])
    x=sorted(x, key=lambda x: (x[0], x[1]))
    for i in range(1,len(x)):
        x[i][1]=min(x[i][1],x[i-1][1])
    d={}
    for i in range(len(x)):
        y=d.get(x[i][0],10**(9))
        d[x[i][0]]=min(y,x[i][1])
    ans=[-1]*n
    j=0
    for i in range(1,n+1):
        y=d.get(i,-1)
        if y==-1:
            ans[i-1]=ans[i-2]
        else:
            ans[i-1]=y
    
    sys.stdout.write(" ".join(map(str,ans)) + "\n")