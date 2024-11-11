def fxn1(arr,ls,j,m1=10**9):
    for i in range(0,j):
        if arr[i]<arr[j]:
            m1=min(m1,ls[i])
    return m1

def fxn2(arr,ls,j,m2=10**9):
    for k in range(j+1,len(arr)):
        if arr[k]>arr[j]:
            m2=min(m2,ls[k])
    return m2
t1=10**9
t2=10**9
z=10**9
n=int(input())
arr=list(map(int,input().split()))
ls=list(map(int,input().split()))
for j in range(1,n-1):
    t1=fxn1(arr,ls,j)
    t2=fxn2(arr,ls,j)
    z=min(ls[j]+t1+t2,z)
if z==10**9:
    print(-1)
else:
    print(z)
