def Dragon(x,y,s,n) :
    for i in range(n) :
        if s<=x[i] :
            return "NO"
        else :
            s+=y[i]
    return "YES"
s,n=map(int,input().split())
x,y=[],[]
for i in range(n) :
    a,b=map(int,input().split())
    x.append(a)
    y.append(b)
for i in range(1,n,1) :
    for j in range(0,n-i,1) :
        if x[j]> x[j+1] :
            x[j],x[j+1]=x[j+1],x[j]
            y[j],y[j+1]=y[j+1],y[j]
print(Dragon(x,y,s,n))
    