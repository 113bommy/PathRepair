t=int(input())
for i in range(t):
    x,y=map(int,input().split())
    if(x==1):
        print(0)
    elif(x==2):
        print(y)
    else:
        print(y*2)