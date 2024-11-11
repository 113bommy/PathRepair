x=int(input(""))
flag=0
for i in range(1,x+1):
    if(flag==1):
        break
    for j in range(1,x+1):
        a=i
        b=j
        if(a*b>x and a%b==0 and a/b<x):
            s=str(a)+" "+str(b)
            flag=1
            break

        else:
            continue
if(flag==1):
    print(s)
else:
    print("-1")
