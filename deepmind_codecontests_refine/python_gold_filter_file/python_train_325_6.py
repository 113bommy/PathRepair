n,x,y=map(int,input().split())
a=(input())
arr=list(map(int, (a)))
arr=arr[n-x:n]
count=0
for a in range(x):
    if(a==(x-y-1)):
        if(arr[a]==0):
            count+=1
    elif(arr[a]==1):
        count+=1
print(count)
