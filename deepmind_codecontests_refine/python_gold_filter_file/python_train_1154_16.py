count=0

n,m=input().split(' ')
n=int(n)
m=int(m)
tp=[0]*n
arr=input().split(' ')
for i in range(n):
    arr[i]=int(arr[i])
    count+=arr[i]
    if(count>=m):
        tp[i]=int(count/m)
        count=count%m
print(*tp,sep=' ')