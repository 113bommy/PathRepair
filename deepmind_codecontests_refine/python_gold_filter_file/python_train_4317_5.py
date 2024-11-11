
def bsearch(arr, n):
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = (l+r) // 2
        if arr[mid] >= n and arr[mid-1] < n:
            return mid + 1
        elif arr[mid] < n:
            l = mid + 1
        else:
            r = mid - 1
    if mid == 0:
        return 1
    else:
        return len(arr)


n = int(input())
wrms = [int(x) for x in input().split()]
m = int(input())
pos = [int(x) for x in input().split()]
sm = 0
cumu = []
for i in range(len(wrms)):
    sm += wrms[i]
    cumu.append(sm)
for ele in pos:
    print(bsearch(cumu, ele))