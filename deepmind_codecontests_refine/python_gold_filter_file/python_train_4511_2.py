for _ in range(int(input())):
    n=int(input())
    if(n%2==0):
        for i in range(1,n+1):
            if(i%2==0):
                print(i-1,end=" ")
            else:
                print(i+1,end=" ")
        print()
    else:
        print("3 1 2",end=" ")
        for i in range(4,n+1):
            if(i%2==0):
                print(i+1,end=" ")
            else:
                print(i-1,end=" ")
        print()