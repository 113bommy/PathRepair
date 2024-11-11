n=int(input())
arr=list(map(int,input().split()))
arr.sort()
ans=0
for i in range(n):
  for j in range(i+1,n):
    for k in range(j+1,n):
      if arr[i]<arr[j] and arr[j]<arr[k]:
        if arr[i]+arr[j]>arr[k]:
          ans+=1
print(ans)
