def solve():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    su = sum(arr)
    if n == 1:
        return max(0, su-k)
    if su <= k:
        return 0
    ans = 10**18
    if arr[0]*n <= k:
        t = 0
        for i in range(n-1, -1, -1):
            su -= arr[i]-arr[0]
            t += 1
            if su <= k:
                ans = t
                break
    su = sum(arr)-arr[0]
    t = 1
    for i in range(n-1, -1, -1):
        ans = min(ans, max(arr[0]-(k-su)//t, 0)+t-1)
        su -= arr[i]
        t += 1
    return ans



import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for i in range(t):
    print(solve())