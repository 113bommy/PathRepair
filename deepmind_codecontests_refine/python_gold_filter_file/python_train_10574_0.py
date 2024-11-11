m=input()
l=['a','b','c','d']
i=0

for i in range(0,len(m)):
    if  m[i]!='!' and (m[i] not in l):
    #   print(m[i],"at",i,"and index=",i%4)
        l[i%4]=m[i]
    # if (len(l)==4):
    #     break
# print(type(len(l)))
# print(l)
cr=0
cb=0
cy=0
cg=0
for i in range(0,len(m)):
    if m[i]=='!':
        color=l[i%4]
        # print(color)
        if color=='R':
            cr+=1
        elif color=='Y':
            cy+=1
        elif color=='G':
            cg+=1
        else:
            cb+=1
print(cr,cb,cy,cg)
    