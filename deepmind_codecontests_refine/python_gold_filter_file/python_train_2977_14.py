m,n=map(int,input().split())
t=2
count=0
x=m
l=[]
while t<=m-1 and m>0:
    #print(m,t,"   ")
    if m%t==0:
        count+=1
        #print(m,t)
        m//=t
        l.append(t)
    else:
        t+=1
    #print(m,t)
if m>1:
    count+=1
    l.append(m)
#print(l)
if count>=n:
    ln=l[:n]
    if count!=n:
        i,temp=n,1
        while count!=n and i<len(l):
            temp*=l[i]
            i+=1
            count-=1
        ln[-1]*=temp
    for i in ln:
        print(i,end=" ")
else:
    print(-1)
