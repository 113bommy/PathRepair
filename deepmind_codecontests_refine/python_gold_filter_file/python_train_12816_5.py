n,m=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
ans=0
height=0
for i in range(n):
    if(arr[i]>height):
        ans+=1
        height+=1
    else:
        ans+=1

if(arr[-1]>height):
    ans+=(arr[-1]-height)
print(sum(arr)-ans)