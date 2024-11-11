n,k=map(int,input().split())

if k==0:
    for i in range(1,n+1):
        print(i,end=" ")
else:
    for i in range(k+1,0,-1):
        print(i,end=" ")
    for i in range(k+2,n+1):
        print(i,end=" ")