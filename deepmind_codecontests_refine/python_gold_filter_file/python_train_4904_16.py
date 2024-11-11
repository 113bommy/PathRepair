n=int(input())
if n==1 or n==0 or n==2:
    print("No")
elif n%2==0:
    print("Yes")
    print(n//2,end=" ")
    for j in range(1,n+1):
        if j%2==0:
            print(j,end=" ")
    print()
    print(n//2,end=" ")
    for j in range(1,n+1):
        if j%2==1:
            print(j,end=" ")
elif n%2==1:
    print("Yes")
    print(n//2,end=" ")
    for j in range(1,n+1):
        if j%2==0:
            print(j,end=" ")
    print()
    print(n//2+1,end=" ")
    for j in range(1,n+1):
        if j%2==1:
            print(j,end=" ")