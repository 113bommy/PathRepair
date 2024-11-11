f=0
a=input().split()
b=input().split()
c=input().split()
t=0
if a[1]=="1" :
    for i in range(len(b)) :
        if b[i]=="0" :
            b[i]=c[0]
    f=0
    for i in range(len(b)-1) :
        if int(b[i])>int(b[i+1]) :
            t=t+1
    if t==0 :
        f=1
if f==1 :
    print("NO")
else :
    print("YES")
