n=int(input())
arr=list(map(int,input().split()))
s=sum(arr)
ans=0
x=arr[0]
for i in range(1,n):
    if x==s-x:
        ans+=1
    x+=arr[i]
print(ans)
