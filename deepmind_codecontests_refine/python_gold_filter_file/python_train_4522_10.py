d={'a':1,'b':2,'c':3,'d':4,'e':5,'f':6,'g':7,'h':8}
start=input()
des=input()
l=[]
x,y=int(start[1]),d[start[0]]
x1,y1=int(des[1]),d[des[0]]
while(x!=x1 or y!=y1):
    if(x==x1):
        if(y<y1):
            l.append('R')
            y+=1
        else:
            l.append('L')
            y-=1
    elif(y==y1):
        if(x<x1):
             l.append('U')
             x+=1
        else:
            l.append('D')
            x-=1
    elif(x>x1 and y<y1):
        l.append('RD')
        x-=1
        y+=1
    elif(x>x1 and y>y1):
        l.append('LD')
        x-=1
        y-=1
    elif(x<x1 and y>y1):
        l.append('LU')
        x+=1
        y-=1
    elif(x<x1 and y<y1):
        l.append('RU')
        x+=1
        y+=1
print(len(l))
for i in l:
    print(i)
