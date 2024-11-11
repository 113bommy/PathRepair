for _ in range(int(input())):
    n=int(input())

    arr=list(map(int,input().split()))
    pos=0
    neg=0
    zero=0
    i=1
    for i in range(n):
        arr[i]=abs(arr[i])
    for i in range(1,n-1,2):

        a=arr[i-1]
        b=arr[i]
        c=arr[i+1]

        if(b>=a and b>=c):
            pass
        elif(b<=a and b<=c):
            pass
        elif(b<=a and b>=c):
            b=-b
            c=-c
        elif(b>=a and b<=c):
            c=-c
        arr[i-1]=a
        arr[i]=b
        arr[i+1]=c




    
    for i in range(1,len(arr)):
        if(arr[i]-arr[i-1]>0):
            pos+=1
        elif(arr[i]-arr[i-1]<0):
            neg+=1
        else:
            zero+=1
    print(*arr)
    # print([pos,neg,zero])