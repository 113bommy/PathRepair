x1,y1,x2,y2 = list(map(int,input().split()))
if(x1 == x2):
    if(y1!=y2):
        z = abs(y1-y2)
        print(x1+z,y1,x2+z,y2)
elif(y1 == y2):
    if(x1!=x2):
        z = abs(x1-x2)
        print(x1,y1-z,x2,y2-z)
elif(abs(x2-x1)==abs(y2-y1)):
    print(x1,y2,x2,y1)
else:
    print(-1)