n=int(input())
if n==1 or n==2:
    print("No")
else:
    print("Yes")
    print(n//2,end=" ")
    for i in range(2,n+1,2):
        print(i,end=" ")
    print()
    print(n-n//2,end=" ")
    for i in range(1,n+1,2):
        print(i,end=" ")