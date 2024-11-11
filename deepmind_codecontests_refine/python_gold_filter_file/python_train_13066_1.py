n, k = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0] * 1000001
t = 0

left = 0
right = -1

l = 0
r = 0
while r < n:
    if cnt[a[r]] > 0: # already have this one
        cnt[a[r]] += 1
        r += 1
    elif t < k: # still has capacity
        cnt[a[r]] = 1
        t += 1
        r += 1
    else:
        # final answer for starting from l
        if r - l > right - left + 1:
            left = l
            right = r - 1

        # prepare for next answer
        cnt[a[l]] -= 1
        if cnt[a[l]] == 0:
            t -= 1
        l += 1

if r - l > right - left + 1:
    left = l
    right = r - 1

print(left + 1, right + 1)