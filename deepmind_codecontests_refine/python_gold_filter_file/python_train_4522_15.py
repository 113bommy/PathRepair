s1=input()
s2=input()
y=ord(s2[0])-ord(s1[0])
x=int(s2[1])-int(s1[1])
if abs(x)>abs(y):
    side=abs(y)
    g=abs(x)
else:
    side=abs(x)
    g=abs(y)
if y>=0 and x>=0:
    s="RU"
elif y<0 and x>=0:
    s="LU"
elif y>=0 and x<0:
    s="RD"
else:
    s="LD"
l=[s]*side
if side==abs(x):
    if y>0:
        for i in range(g-side):
            l.append("R")

    else:
        for i in range(g-side):
            l.append("L")
else:
    if x>0:
        for i in range(g-side):
            l.append("U")
    else:
        for i in range(g-side):
            l.append("D")
print(str(len(l)))
for i in range(len(l)):
    print(l[i])






