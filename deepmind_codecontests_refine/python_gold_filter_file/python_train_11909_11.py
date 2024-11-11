
n = int(input())
if(n%2==0):
    print(-1)
else:
    for i in range(n):
        print(i,end=" ")
    print()
    for i in range(n-1,-1,-2):
        print(i,end=" ")
    for i in range(n-2,-1,-2):
        print(i,end=" ")
    print()
    for i in range(n-1,-1,-1):
        print(i,end=" ")