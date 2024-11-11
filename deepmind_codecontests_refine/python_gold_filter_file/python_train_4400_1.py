n=int(input())
a=list(map(int,input().split()))
for j in range(1,n+1):
    for i in range(0,n):
        if(a[i]==j):
            print(i+1,end=" ")