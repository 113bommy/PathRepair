n,k,x=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
arr2=[]
for i in range(n):
    if arr[i]-arr[i-1]>x:
        arr2.append((arr[i]-arr[i-1]-1)//x)
arr2.sort(reverse=True)
while(len(arr2)>0):
    if arr2[len(arr2)-1]<=k:
        k=k-arr2[len(arr2)-1]
        arr2.pop(len(arr2)-1)
    else:
        break
print(len(arr2)+1)