n=int(input())
f=list(map(int,input().split()))
for i in range(1,n+1):
    print(f.index(i)+1,end=" ")