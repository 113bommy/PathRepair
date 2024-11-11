from itertools import accumulate

n, k = map(int, input().split())
a = list(map(int, input().split()))

for j in range(k):
    a01 = [0] * (n + 1)
    for i, ai in enumerate(a):
        l, r = max(0, i - ai), min(i + ai + 1, n)
        a01[l] += 1
        a01[r] -= 1
    a = list(accumulate(a01))[:-1]
    if all(ai == n for ai in a):
        break
print(*a)
