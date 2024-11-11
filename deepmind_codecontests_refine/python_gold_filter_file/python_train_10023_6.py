t=int(input())
for j in range(0,t):
    n,m=map(int,input().split())
    ui=0
    for o in range(0,n):
        x,y=map(int,input().split())
        v,w=map(int,input().split())
        if(y==v):
            ui+=1
    if(m%2!=0):
        print("NO")
    else:
        if(ui>0):
            print("YES")
        else:
            print("NO")
        
