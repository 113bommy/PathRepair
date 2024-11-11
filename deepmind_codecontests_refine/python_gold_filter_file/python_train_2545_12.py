x1,y1,x2,y2=input().split()
x1=int(x1)
x2=int(x2)
y1=int(y1)
y2=int(y2)
if x1==x2 and y1==y2:
    print(-1)
elif x1==x2 and y1!=y2:
    s=(y2-y1)
    print(x2+s, y2, x1+s, y1)
elif x1!=x2 and y1==y2:
    s=(x2-x1)
    print(x1, y1+s, x2, y2+s)
elif x1!=x2 and y1!=y2:
    if y1-y2==x2-x1 or y1-y2==x1-x2:
        print(x1, y2, x2, y1)
    else:
        print(-1)
else:
    print(-1)