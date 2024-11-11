n,k=map(int,input().split())
arr=[int(i) for i in input().split()]
if n==1:
    for i in arr:
        print(i)
    exit()
c=1
for i in range(k):
    print(arr[i],end=" ")
    x=0
    con=1
    while(con):
        if c not in arr:
            print(c,end=" ")
            x=x+1
            if x==n-1:
                con=0
        c=c+1
    print()