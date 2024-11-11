a,x,y=map(int,input().split())
if y%a==0 : print(-1)
elif y//a==0: print(1 if x>-a/2 and x<a/2 else -1)
else:
    y//=a;
    if y&1:
        print((3*y+1)//2 if x>-a/2 and x< a/2 else -1)
    else:
        if x==0 or x<=-a or x>=a : print(-1)
        else: print((3*y)//2 if x<0 else (3*y)//2+1)