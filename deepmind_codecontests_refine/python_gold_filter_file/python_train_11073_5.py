n=int(input())
if n == 1 or n == 2:
    print(-1)
else:
    print(n,end=" ")
    for i in range(n-1,0,-1):
        print(i,end=" ")