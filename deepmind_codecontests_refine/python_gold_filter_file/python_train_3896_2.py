import sys
x1,y1,x2,y2=map(int,input().split())
#rook
if(x1==x2 or y1==y2): sys.stdout.write("1 ")
else:sys.stdout.write("2 ")
#bishop
if ((x1-x2)%2==0 and y1%2!=y2%2)or((x1-x2)%2!=0 and y1%2==y2%2): sys.stdout.write("0 ")
else:
    if x1==x2:
      if y1%2==y2%2:sys.stdout.write ("2 ")
      else:sys.stdout.write("0 ")
    elif y1==y2: 
      if x1%2==x2%2:sys.stdout.write ("2 ")
      else:sys.stdout.write("0 ")
    elif (abs((y1-y2)/(x1-x2))==1.0):sys.stdout.write("1 ")
    else: sys.stdout.write("2 ")
#king
if(abs(x1-x2)>abs(y1-y2)):print(abs(x1-x2))
else:print(abs(y1-y2)) 