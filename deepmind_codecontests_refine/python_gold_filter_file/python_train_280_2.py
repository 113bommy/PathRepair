n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
arr.append(2000000000)
n+=1
j=0
k2=0
for i in range(n-1):
    while(j<n and arr[j]==arr[i]):
         j+=1
    if(arr[j]-arr[i]>k):
        k2+=1
print(k2)

        
