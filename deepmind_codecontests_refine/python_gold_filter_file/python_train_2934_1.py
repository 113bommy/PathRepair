s=input()
n=len(s)
b=[0]*n
l=[]
m=[]
j=0
for i in s:
    if(len(l)==0):
        l.append(i)
        m.append(j)
    elif(l[-1]=='1' and i=='0'):
        l.pop()
        b[m.pop()]=1
    else:
        l.append(i)
        m.append(j)
    j+=1
print(*b,sep="")