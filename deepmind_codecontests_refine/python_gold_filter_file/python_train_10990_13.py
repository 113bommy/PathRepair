a=[31,28,31,30,31,30,31,31,30,31,30,31]
m,d=map(int,input().split())
k=a[m-1]
k+=d-1
if k%7==0:
    print(k//7)
else:
    print(k//7+1)
