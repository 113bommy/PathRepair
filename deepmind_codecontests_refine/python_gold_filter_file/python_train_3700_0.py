
"""
def sol(arr):
    n = len(arr)
#    avg = int(np.mean(arr))
#    print(avg)

#    for i in range(n):
#        arr[i]-=avg
    for i in range(n-1):
        arr[i+1]+=arr[i]

    res = arr.count(max(set(arr),key=arr.count))
    return n-res
    """
def sol1(arr):
    mp = {}
    cnt = 0
    n = len(arr)
    ans = 0
    for a in arr:
        ans += a
        if ans in mp:
            mp[ans] += 1
        else:
            mp[ans] = 1
#        cnt = min(cnt, n - mp[ans])
        cnt = max(cnt, int(mp[ans]))

    return n-cnt


n = int(input())
arr = list(map(int,input().split()))
print(sol1(arr))
