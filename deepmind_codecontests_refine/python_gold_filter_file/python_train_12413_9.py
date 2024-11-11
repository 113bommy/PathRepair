from collections import Counter

tc = int(input())
for _ in range(tc):
    n = int(input())
    *nums, = map(int, input().split())
    cnt = Counter(nums)
    distinct = len(set(cnt))
    same_key = max(cnt, key=lambda k: cnt[k])
    ans = min(distinct, cnt[same_key])
    if distinct == cnt[same_key]:
        ans -= 1
    print(ans)






