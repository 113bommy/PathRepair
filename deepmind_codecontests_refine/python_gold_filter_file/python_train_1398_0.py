

l=[]
for i in range(1,9):
    for j in range(1,9):
        l.append(int(str(i)+str(j)))
l2=[]
def check(l2,c,d):
    if c+1<=8 and d+2<=8:
        l2.append(int(str(c+1)+str(d+2)))
    if c+2<9 and d+1<9:
        l2.append(int(str(c+2)+str(d+1)))
    if c-1>0 and d-2>0:
        l2.append(int(str(c-1)+str(d-2)))
    if c-2>0 and d-1>0:
        l2.append(int(str(c-2)+str(d-1)))
    if c+1<9 and d-2>0:
        l2.append(int(str(c+1)+str(d-2)))
    if c-1>0 and d+2<9:
        l2.append(int(str(c-1)+str(d+2)))
    if c+2<9 and d-1>0:
        l2.append(int(str(c+2)+str(d-1)))
    if c-2>0 and d+1<9:
        l2.append(int(str(c-2)+str(d+1)))
#input
r=input()
k=input()
r1=str(ord(r[0])-96)+r[1]
k1=str(ord(k[0])-96)+k[1]


#for rook given
a,b=int(r1[0]),int(r1[1])
# print(a,b)
for i in range(1,9):
    for j in range(1,9):
        if i==a or j==b:
            l2.append(int(str(i)+str(j)))
check(l2,a,b)
 
    
    
#for knight
c,d=int(k1[0]),int(k1[1])
check(l2,c,d)
l2.append(int(str(c)+str(d)))   #pos of curr knight
#answer    
print(64-len(set(l2)))    
    
    
    
    
    
    
    
    
    
