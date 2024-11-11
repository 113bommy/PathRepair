from itertools import accumulate
R = lambda: map(int, input().split())
s = input()
d1 = list(accumulate(int(c.islower()) for c in s))
d2 = list(accumulate(int(c.isupper()) for c in s[::-1]))[::-1]
res = len(s)
for i in range(1, len(s) - 1):
    res = min(res, d1[i - 1] + d2[i + 1])
print(min(d1[-1], d2[0], res))