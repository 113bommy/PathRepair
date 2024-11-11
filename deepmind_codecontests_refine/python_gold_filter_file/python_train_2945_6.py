t=int(input())
for i in range(t):
    n=int(input())
    a=[[0 for j in range(n)] for i in range(n)]
    curr=0
    last=1
    for i in range(n):
        a[i][curr%n]=4
        a[i][last%n]=1
        curr+=1
        last+=1

    for j in a:
        print(*j)


