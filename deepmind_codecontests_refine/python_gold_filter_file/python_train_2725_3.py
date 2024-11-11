t=int(input())
while t:
    n=int(input())
    d=input()
    d=[d[i] for i in range(n)]
    ls=["" for i in range(n)]
    i=n-1
    mini='9'
    while i>=0:
        mini=min(mini,d[i])
        ls[i]=mini
        i-=1
    color=[0 for i in range(n)]
    x="9"
    for i in range(n):
        if(d[i]<=ls[i] and d[i]<=x):color[i]=1
        else:
            color[i]=2
            x=min(x,d[i])
    ans=[]
    for i in range(n):
        if(color[i]==1):ans.append(d[i])
    for i in range(n):
        if(color[i]==2):ans.append(d[i])
    d.sort()
    if(ans==d):
        print("".join(str(x) for x in color))
    else:
        print("-")
    t-=1