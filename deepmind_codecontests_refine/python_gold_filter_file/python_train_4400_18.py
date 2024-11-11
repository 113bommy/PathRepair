n=int(input())
arr=list(map(int,input().split()))
for i in range(1,n+1):
    print(arr.index(i)+1,end=" ")