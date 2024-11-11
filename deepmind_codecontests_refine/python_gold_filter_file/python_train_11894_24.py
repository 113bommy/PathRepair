for i in range(int(input())):
    n=int(input())
    j=1
    if(n<=3):
        print(-1)
        continue
    if(n==4):
        print("3 1 4 2")
        continue
    while(j<(n+1)):
        print(j,end=" ")
        j=j+2
    j=j-2
    a=j-3
    print(j-3,end=" ")
    if((j+1)>n):
        j=j-1
    else:
        j=j+1
    while(j>0):
        if(j==a):
            pass
        else:
            print(j,end=" ")
        j=j-2
    print()
    
        
