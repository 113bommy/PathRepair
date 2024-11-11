t=int(input())
while t>0:
    n=int(input())
    arr=[int(i) for i in input().split()]
    count=0
    a=0
    b=0
    for x  in range(len(arr)):
        if arr[x]%3==0:
            count+=1
        elif arr[x]%3==1 :
            a+=1
        else:
            b+=1
    if  a>=b :
        k=a-b
        count=count+b
    else  :
        k=b-a
        count=count+a
    count=count+int(k/3)
    print(count)
    t=t-1
    
    
