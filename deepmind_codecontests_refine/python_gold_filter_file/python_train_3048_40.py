n =int(input())
for i in range(n):
    a,b=map(int,input().split())
    #print(a,b)
    x=bin(max(a,b))
    y=bin(min(a,b))
    y=y.replace("0b","")
    x=x.replace("0b","")
    y="0"*(len(x)-len(y))+y
    z=""
    ans=0
    #print(x,y)
    for i in range(len(x)):
        #print(x[i])
        if (x[i]!=y[i]): z+="0"
        elif (x[i]=='1'):
            z+="1"
            ans+=2**(len(x)-i-1)
        else: z+="0"
    z="0b"+z
    #print(ans)
    zx=a^ans+(b^ans)
    print(zx)
