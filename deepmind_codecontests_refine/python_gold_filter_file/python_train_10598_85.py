r,d,x=map(int,input().split())
tmp=x
for i in range(10):
    x=r*x-d
    print(x)
