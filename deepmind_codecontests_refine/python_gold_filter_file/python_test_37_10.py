for u in range(int(input())):
    n,m=map(int,input().split())
    d=[0 for j in range(n)]
    for i in range(m):
        a,b,c=map(int,input().split())
        d[b-1]=1
    f=-1
    for i in range(n):
        if(d[i]==0):
            f=i+1
            break
    for i in range(n):
        if(i+1!=f):
            print(f,i+1)
