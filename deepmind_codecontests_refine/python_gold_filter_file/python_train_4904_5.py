n=int(input())
if n<=2:
    print("No")
else:
    print("Yes")
    if n%2==0:
        k=n//2
    else:
        k=(n+1)//2
    print(1,end=" ")
    print(k)
    print(n-1,end=" ")
    for i in range(1,n+1):
        if i==k:
            continue
        else:
            print(i,end=" ")
            
    