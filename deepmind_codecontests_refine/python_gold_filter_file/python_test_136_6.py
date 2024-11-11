import sys

t = int(sys.stdin.readline())
ans = []
for _ in range(t):
    n = int(sys.stdin.readline())
    nums = list(map(int, sys.stdin.readline().split()))
    m = n * (n + 1) // 2
    tot = sum(nums)
    if tot % m:
        print('NO')
        continue
    tot //= m
    res = []
    for i in range(n):
        ai = tot - (nums[(i + 1) % n] - nums[i])
        if ai % n or ai <= 0:
            break
        res.append(ai // n)
    if len(res) < n:
        print('NO')
    else:
        print('YES')
        print(' '.join(map(str, [res[-1]] + res[:n - 1])))