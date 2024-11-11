import sys
n,m=map(int,sys.stdin.readline().split())
M=[m]
A=list(map(int,sys.stdin.readline().split()))
L=[0]*n
inc=False
dec=False
def ALLYes():
    Ans=""
    for i in range(M[0]):
        Ans+="Yes\n"
    sys.stdout.write(Ans)
    return
for i in range(1,n):
    if(A[i]>A[i-1]):
        L[i]=1
        inc=True
    elif(A[i]==A[i-1]):
        L[i]=0
    else:
        L[i]=-1
        dec=True
if(inc==False or dec==False):
    ALLYes()
else:
    neg=L.index(-1)
    pos=L.index(1)
    First=[-1]*n
    for i in range(2,n):
        if(L[i]==0):
            x=max(neg,pos)
            if(x<=i):
                First[i]=x
            elif(min(neg,pos)<=i):
                First[i]=min(neg,pos)
            else:
                First[i]=-1
        if(L[i]==1):
            if(neg>i):
                First[i]=-1
            else:
                First[i]=neg
            pos=i
        if(L[i]==-1):
            if(pos>i):
                First[i]=-1
            else:
                First[i]=pos
            neg=i
    Ans=""
    for i in range(m):
        l,r=map(int,sys.stdin.readline().split())
        r-=1
        if(r-l<1):
            Ans+="Yes\n"
            continue
        if(L[r]==0):
            r=First[r]
            if(r<1):
                Ans+="Yes\n"
                continue
        if(L[r]==1):
            r=First[r]
            if(r<l):
                Ans+="Yes\n"
                continue
            else:
                Ans+="No\n"
                continue
        elif(L[r]==-1):
            r=First[r]
            if(r<l):
                Ans+="Yes\n"
                continue
            r=First[r]
            if(r<l):
                Ans+="Yes\n"
                continue
            else:
                Ans+="No\n"
                continue
    sys.stdout.write(Ans)
    
    
