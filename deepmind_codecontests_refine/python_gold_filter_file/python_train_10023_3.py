a=int(input())
for i in range(0,a):
    b=list(map(int,input().split()))
    d=[]
    y=0
    for j in range(0,b[0]):
        c=list(map(int,input().split()))
        e=list(map(int,input().split()))
        if(c[1]==e[0]):
            y=1
    if(y==1 and b[1]%2==0):
        print("YES")
    else:
        print("NO")
        