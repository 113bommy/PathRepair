import sys
t=int(sys.stdin.readline())
for i in range(t):
    x,y=list(map(int,sys.stdin.readline().strip().split()))
    f=1
    if(x==y):
        f=1
    elif(x==1):
        if(y==0):
            f=1
        else:
            f=0
    elif(x==2 or x==3):
        if(y==1 or y==0 or y==3 or y==2):
            f=1
        else:
            f=0
    else:
        f=1
    if(f):
        print("YES")
    else:
        print("NO")