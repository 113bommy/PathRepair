t=int(input())
while(t>0):
    t=t-1
    n=int(input())
    b=[2]
    x=3
    for i in range(n-1):
        b.append(x)
        x+=1
    print(*b)
        