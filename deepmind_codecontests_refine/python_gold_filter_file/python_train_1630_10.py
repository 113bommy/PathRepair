from math import ceil
k, d, t = [int(x) for x in input().split()]
if d < k:
    d = ceil(k / d) * d
c = k + (d - k) / 2
l = 0
r = int(1e18) + 1
while l < r:
    s = (l + r) // 2
    if s * c <= t:
        l = s + 1
    else:
        r = s
l -= 1
res = l * d
t -= l * c
if t > k:
    res += k + (t - k) * 2
else:
    res += t
print(res)



