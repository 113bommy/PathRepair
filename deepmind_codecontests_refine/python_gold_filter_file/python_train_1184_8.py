
n,k = list(map(int,input().split()))
start = k-1
end = 1


def bsearch(start,end):
    if start<end:
        return start
    else:
        mid = start-(start-end)//2
        val = ((k-1)*k//2) - ((mid-1)*mid//2) +1
        if val==n:
            return mid
        elif val>n:
            end = mid+1
        else:
            start = mid-1
        return bsearch(start,end)

ans = bsearch(start,end)


if ans == 0:
    print(-1)
elif n==1:
    print(0)
else:
    print(k-ans)
