n,q=list(map(int,input().strip().split()))
a=[]
for i in range(n):
    a.append([0,0])
bl=0
for i in range(q):
    b,c=list(map(int,input().strip().split()))
    if a[c-1][b-1]==0:
        a[c-1][b-1]=1
        if a[c-1][abs(b-1-1)]==1:
            bl=bl+1
        if c<n:
            if a[c][abs(b-1-1)]==1:
                bl=bl+1
        if c>1:
            if a[c-2][abs(b-1-1)]==1:
                bl=bl+1
    
    elif a[c-1][b-1]==1:
        a[c-1][b-1]=0
        if a[c-1][abs(b-1-1)]==1:
            bl=bl-1
        if c<n:
            if a[c][abs(b-1-1)]==1:
                bl=bl-1
        if c>1:
            if a[c-2][abs(b-1-1)]==1:
                bl=bl-1
    if bl==0:
        print("Yes")
    else:
        print("No")