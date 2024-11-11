for _ in range(int(input())):
    x,y = map(int,input().split())
    if(x==3 and (y>3)): print("NO")
    elif(x==1 and y!=1): print("NO")
    elif(x==2 and (y>3)): print("NO")
    else: print("YES")
        