from bisect import bisect as bs
n, q = map(int, input().split())
a = list(map(int, input().split()))
k = list(map(int, input().split()))
tmp = 0
sumA = []
for i in range(n):
    tmp += a[i]
    sumA.append(tmp)
# print(sumA)


def bin_search(left, right, v):
    
    mid = (left + right) >> 1
    if left > right:
        return left
    if sumA[mid] == v:
        return mid + 1
    elif sumA[mid] < v:
        return bin_search(mid+1, right, v)
    else:
        return bin_search(left, mid-1, v)


def bin_sea_while(lo, hi, x):
    while lo < hi:
        mid = (lo+hi)//2
        if x < sumA[mid]: hi = mid
        else: lo = mid+1
    return lo


now = 0

ansList = []

for i in range(q):
    now += k[i]
    ans_id = bin_sea_while(0, n, now)
    if ans_id == n:
        now = 0
        ans_id = 0
    ansList.append(n-ans_id)

print("\n".join(map(str, ansList)))