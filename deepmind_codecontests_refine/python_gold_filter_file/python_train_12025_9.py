n=int(input())
s=0
a=[]
b=[]
for i in range(0,n):
    x=input()
    xx=x.split( )
    a.append(int(xx[0]))
    b.append(int(xx[1]))
if len(a)==1:
    print(a[0]*b[0])
else:
    i=0
    while i!=n:
        if i!=n-1:
            h=i
            s+=(b[i]*a[i])
            q=0
            while b[i]<b[h+1]:
                s+=(b[i]*a[h+1])
                h+=1
                q+=1
                if h==n-1:
                    break
            if q!=0:
                i=h+1
            else:
                i+=1
        else:
            if i!=h:
                s+=(b[i]*a[i])
            i+=1
    print(s)
        
