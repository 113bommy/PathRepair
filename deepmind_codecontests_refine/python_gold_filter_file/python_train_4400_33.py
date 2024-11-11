n=int(input())
x=list(map(int,input().split()))
for i in range(1,n+1):
    print(x.index(i)+1,end=" ")
