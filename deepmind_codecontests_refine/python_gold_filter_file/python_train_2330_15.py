n,k=[int(x) for x in input().split()]
arr=[int(x) for x in input().split()]
start=0
end=0
ans=0
s=0
l=0
while end<n:
    s+=arr[end]
    l+=1
    if s<=k:
        ans=max(ans,l)
    while start<=end and s>k:
        if s<=k:
            ans=max(ans,l)
        l-=1
        s-=arr[start]
        start+=1
        if s<=k:
            ans=max(ans,l)
    end+=1
if s<=k:
    ans=max(ans,l)
print(ans)