import itertools
n, k = map(int, input().split())
sums = (0,) + tuple(itertools.accumulate(map(int, input().split())))
S = l = r = ans = pos = 0
for i in range(k, n - k + 1):
    if sums[i] - sums[i - k] > S:
        S = sums[i] - sums[i - k]
        pos = i - k
    if S + sums[i + k] - sums[i] > ans:
        ans = S + sums[i + k] - sums[i]
        l = pos
        r = i
print(l + 1, r + 1)