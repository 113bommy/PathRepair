for  i in range(int(input())):   
    n=int(input())
    arr=list(map(int,input().split()))
    b=0
    a=0
    for i in range(n):
        b^=arr[i]
        a+=arr[i]
    print(2)
    print(b,a+b)    