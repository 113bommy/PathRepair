x1,y1,x2,y2=map(int,input().split())
if x1==x2:
    x=abs(y1-y2)
    print(x1+x,y1,x2+x,y2)
elif y1==y2:
    x=abs(x1-x2)
    print(x1,y1+x,x2,y2+x)
else:
    if abs(x1-x2)!=abs(y1-y2):
        print(-1)
    else:
        x=abs(y1-y2)
        if y1<y2:
           print(x1,y1+x,x2,y2-x)
        else:
             print(x1,y1-x,x2,y2+x)
            
