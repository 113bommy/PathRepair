n=int(input())
l=list(map(int, input().split()))

if n==1:
    print(-1)
    exit(0)

if n==2:
    if l[0]==l[1]:
        print(-1)
        exit(0)
    else:
        print(1)
        print(1)
        exit(0)

#print(l[0:n-1],l[n-1:n])
if sum(l[0:n-1]) != sum(l[n-1:n]):
    print(n-1)
    for i in range(1,n):
        print(i,end=" ")
    print()

else:
    print(n - 2)
    for i in range(1, n-1):
        print(i, end=" ")
    print()