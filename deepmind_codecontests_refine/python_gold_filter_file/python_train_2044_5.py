n=int(input())
if n%2==0:
    if n%4==0:
        print(0)
        print(n//2,end=" ")
        for i in range(1,n+1):
            if i%4==0 or (i-1)%4==0:
                print(i,end=" ")
    else:
        print(1)
        print(1+((n-1)//4)*2,end=" ")
        print(1,end=" ")
        for i in range(3,n+1):
            if (i-3)%4==0 or (i-2)%4==0:
                print(i,end=" ")
else:
    if (n-1)%4==0:
        print(1)
        print(1+((n-1)//4)*2,end=" ")
        print(1,end=" ")
        for i in range(2,n+1):
            if (i-2)%4==0 or (i-1)%4==0:
                print(i,end=" ")
    else:
        print(0)
        print(2+((n-3)//4)*2,end=" ")
        print(1,2,end=" ")
        for i in range(4,n+1):
            if i%4==0 or (i-3)%4==0:
                print(i,end=" ")