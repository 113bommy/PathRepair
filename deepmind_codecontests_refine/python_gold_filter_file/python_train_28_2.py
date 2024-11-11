from bisect import *
from math import ceil
for _ in range(int(input())):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    x = list(map(int,input().split()))
    prefMax=[a[0]]*n
    prefSum=[a[0]]*n
    for i in range(1,n):
        prefSum[i] = prefSum[i-1]+a[i]
        prefMax[i] = max(prefMax[i-1],prefSum[i])
    ans = []
    for tar in x:
        curr = -1
        if tar<=prefMax[-1]:
            curr=bisect_left(prefMax,tar)
        else:
            if prefSum[-1]>0:
                tot = ceil((tar-prefMax[-1])/prefSum[-1])
                curr = tot*n + (bisect_left(prefMax,tar-tot*prefSum[-1]) if tar!=tot*prefSum[-1] else -1)
        ans.append(curr)
    print(*ans)