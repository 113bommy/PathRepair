s=input()
x1=s.find('AB')
x2=s.find('BA',x1+2)

y1=s.find('BA')
y2=s.find('AB',y1+2)

if((x1!=-1 and x2!=-1) or (y1!=-1 and y2!=-1)):
    print("YES")
else:
    print("NO")
    
