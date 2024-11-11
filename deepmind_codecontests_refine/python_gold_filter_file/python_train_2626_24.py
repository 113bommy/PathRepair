import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n, p, k = map(int, input().split())
    arr = sorted(list(map(int, input().split())))
    psa = [arr[0]]
    for i in range(1, n):
        psa.append(psa[i-1] + arr[i])
    lo = 0
    hi = n-1
    ans = 0
    while (lo <= hi):
        mid = (lo + hi) >> 1
        sume = psa[mid]
        if mid != 0:
            for i in range(mid, 0, -2):
                sume -= arr[i-1]
        if sume <= p:
           ans = max(ans, mid)
           lo = mid+1
        else:
           hi = mid-1
    if arr[0] > p:
        print(0)
    else:
        print(ans+1)