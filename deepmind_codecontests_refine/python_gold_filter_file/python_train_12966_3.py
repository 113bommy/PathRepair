N=list(map(int,input().split()))
n=N[0]
x=set()
y=set()
xl=0
yl=0
for i in range(N[1]):
    count=n*n
    X,Y=map(int,input().split())
    x.add(X)
    y.add(Y)
    count=count-len(x)*n
    if count!=0:
        count=count-(len(y)*(n-len(x)))
    print(count,end=" ")
