from bisect import bisect_left, bisect_right

n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))

pos_start = bisect_right(a, 0)
neg_end = bisect_left(a, 0)

pos_cnt = n - pos_start
neg_cnt = neg_end

pairs_cnt = n * (n - 1) // 2
pos_pairs_cnt = pos_cnt * (pos_cnt - 1) // 2 + neg_cnt * (neg_cnt - 1) // 2
neg_pairs_cnt = pos_cnt * neg_cnt

if k <= neg_pairs_cnt:
    high = 0
    low = -10 ** 18
    while abs(high - low) > 1:
        mid = (high + low) // 2
        cnt = 0
        r = pos_start
        for l in range(neg_end):
            while r < n and mid < a[r] * a[l]:
                r += 1
            cnt += pos_cnt - (r - pos_start)

        if cnt >= k:
            high = mid
        else:
            low = mid

    print(high)

elif pairs_cnt - pos_pairs_cnt < k:
    k -= (pairs_cnt - pos_pairs_cnt)
    high = 10 ** 18
    low = 0
    while abs(high - low) > 1:
        mid = (high + low) // 2
        cnt = 0
        r = n - 1
        for l in range(pos_start, n):
            while l < r and mid < a[r] * a[l]:
                r -= 1
            cnt += max(0, r - l)
        
        l = 0
        for r in range(neg_end-1, -1, -1):
            while l < r and mid < a[r] * a[l]:
                l += 1
            cnt += max(0, r - l)

        if cnt >= k:
            high = mid
        else:
            low = mid

    print(high)

else:
    print(0)