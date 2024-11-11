from bisect import bisect_left, bisect_right

N, K = map(int, input().split())
As = sorted(map(int, input().split()))
        
l = - (10 ** 18 + 10)
r = 10 ** 18 + 10
while True:
    mid = (l + r) // 2
    count = 0
    for i, A in enumerate(As):
        if A > 0:
            count += bisect_right(As, mid//A, lo = i+1) - (i+1)
        elif A < 0:
            count += N - bisect_left(As, -((-mid)//A), lo = i+1)
        else:
            if mid >= 0:
                count += N - i - 1
    if count < K:
        l = mid
    else:
        r = mid
    if r - l == 1:
        break

print(r)
