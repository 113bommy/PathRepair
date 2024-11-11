n=int(input())
if(n%2==0):
    if(n%4==0):
        print (0)
        print (n//2,end=" ")
        k=1
        for i in range(n//4):
            print (k,end=" ")
            print (n-k+1,end=" ")
            k+=1
    else:
        print (1)
        print (n//2,end=" ")
        k=1
        for i in range(n//4):
            print (k,end=" ")
            print (n-k+1,end=" ")
            k+=1
        print (n//2)
elif(n%2==1):
    a=n*(n+1)//2
    if(a%2==0):
        print (0)
        print ((n+1)//2,end=" ")
        k=(n+1)//4
        for i in range((n+1)//2):
            print (k,end=" ")
            k+=1
    elif(a%2==1):
        print (1)
        print ((n-1)//2,end=" ")
        k=(n+7)//4
        for i in range((n-1)//2):
            print (k,end=" ")
            k+=1