
n,m = map(int,input().strip().split())

arr = list(map(int,input().strip().split()))

arr = sorted(arr,reverse=True)


ak = []

for i in range(n):
    ak.append(arr[i])

for i in range(n-1):
    if arr[i]==min(arr[i],arr[i+1]):
        arr[i+1]=max(1,arr[i]-1)

ans = 0
for i in range(n):
    ans+=ak[i]-arr[i]
#print(ans)
for i in range(n-1):
    if arr[i]!=1:
        ans+=arr[i+1]
        
if len(arr)>1:
    if arr[n-1]!=1:
        ans+=arr[n-1]-arr[n-1]
else:
    ans=0

#print(ak)
#print(arr)

print(ans)
