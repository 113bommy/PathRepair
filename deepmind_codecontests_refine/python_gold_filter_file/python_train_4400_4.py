n=int(input())
g=list(map(int,input().split()))
for i in range(1,n+1):
    print(g.index(i)+1,end=" ")