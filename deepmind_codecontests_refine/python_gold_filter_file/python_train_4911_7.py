n=int(input())
c=0
sp=n
for i in range(n,-1,-1):
    print(2*sp*" ",end="")
    if(i==n):
        print(0)
    else:
        for j in range(c+1):
            print(j,end=" ")
        for j in range(c-1,0,-1):
            print(j,end=" ")
        print(0)
    c+=1
    sp-=1
c=n-1
sp=1
for i in range(1,n+1):
    print(2*sp*" ",end="")
    if(i==n):
        print(0)
    else:    
        for j in range(c+1):
            print(j,end=" ")
        for j in range(c-1,0,-1):
            print(j,end=" ")
        print(0)
    c-=1
    sp+=1
