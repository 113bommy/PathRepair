x,y = [int(i) for i in input().split()]
b = abs(y)
if(x>0 and y>0):
    print(0,x+b,x+b,0)
elif(x>0 and y<0):
    print(0,-x-b,x+b,0)
elif(x<0 and y>0):
    print(x-b,0,0,abs(x)+b)
elif(x<0 and y<0):
    print(y+x,0,0,y+x)
    
    

