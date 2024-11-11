x,y=map(int,input().split())
if x==y==1:
    print(1000000);exit()
A=[300000,200000,100000]+[0]*1000
print(A[x-1]+A[y-1])
