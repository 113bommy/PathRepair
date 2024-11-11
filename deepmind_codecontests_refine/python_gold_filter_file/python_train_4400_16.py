n=int(input())
k=list(map(int,input().split()))
for i in range(1,n+1):
    print(k.index(i)+1,end=" ")