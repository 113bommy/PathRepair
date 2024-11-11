x1,y1,x2,y2=map(int,input().split())
if x1==x2 or y1==y2:
    if x1==x2:
        x1+=(y1-y2);x2+=(y1-y2);print(x1,y1,x2,y2)
    else:
        y1+=(x1-x2);y2+=(x1-x2);print(x1,y1,x2,y2)
elif x1-x2==y1-y2 or x1-x2==y2-y1:
    y2,y1=y1,y2;print(x1,y1,x2,y2)
else:print(-1)
