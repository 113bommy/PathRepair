n=int(input())
for i in range(n):
    x=[]
    for j in range(n):
        if((i+j)&1):
            x.append("B")
        else:
            x.append("W")
    print(*x,sep='')
