def swap(m,n):
    temp= arr[m]
    arr[m]=arr[n]
    arr[n]=temp
def swap_and_modify(arr,l,r,k):
    global count
    if count>=k or r-l<2:
        return
    else:
        m=int((l+r)/2)
        swap(m,m-1)
        count+=2
        swap_and_modify(arr,l,m,k)
        swap_and_modify(arr,m,r,k)

n,k=input().split()
n=int(n)
k=int(k)
arr=[]
global count
count=1
for i in range(1,n+1):
    arr.append(i)

swap_and_modify(arr,0,n,k)
if count!=k:
    print(-1)
else:
    for i in arr:
        print(i,end=" ")


