x,y = map(int,input().split())
if((x==1 and y>4) or (x-y)>=2 or ((y - 2 * x) > 2)):
    print("-1")
    exit()
elif(x-y==1):
    print("0"+"10"*y)
elif((x==y or y-x==1 or y-x==2) and y>=x):
    print("10"*min(x,y)+"1"*(y-x))
else:
        p = y-x
        if(p>x):
            print("110" * x + "1" * (y - 2 * x))
        else:
            print("110"*(p)+"10"*(x-p))