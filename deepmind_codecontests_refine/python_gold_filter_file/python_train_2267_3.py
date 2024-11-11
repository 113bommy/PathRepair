X,N=map(int,input().split())
list1=list(map(int,input().split()))

k=100
for i in range(0,150):
    d=abs(X-i)
    if d<k and(i not in list1):
        k=d
        A=i
print(A)