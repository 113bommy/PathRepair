def bs(k):
    global n
    l = 0
    r = n
    while l < r:
        mid = (l+r) // 2
        if k >= a[mid]:
            if mid == n - 1: return mid+1
            if k < a[mid+1]:
                return mid+1
        if k < a[mid]:
            r = mid
        else:
            l = mid + 1
    return mid

n,m = map(int,input().split())
a = sorted(list(map(int,input().split())))
b = list(map(int,input().split()))

for k in b:
    print(bs(k),end=" ")