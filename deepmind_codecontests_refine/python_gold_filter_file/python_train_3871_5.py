import bisect
n,k = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

arr.sort()

cmedian = arr[n//2]
curr = n//2
to_increase = 0
ans = 0
while True:
    x = bisect.bisect_right(arr,cmedian)
    to_increase += x-curr
    if x<n:
        by_increase = arr[x]-arr[curr]
        if by_increase*to_increase>k:
            by_increase = k//to_increase
            cmedian+=by_increase
            ans=cmedian
            break
        else:
            k-=(by_increase*to_increase)
            cmedian=arr[x]
            curr=x
    else:
        by_increase = k//to_increase
        cmedian+=by_increase
        ans=cmedian
        break
#print(to_increase,by_increase)
print(ans)
