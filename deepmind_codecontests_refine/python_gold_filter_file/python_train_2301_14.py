from collections import Counter

cnt, g = [int(i) for i in input().split()]
in_arr = [int(i) for i in input().split()]
cnt_b = 0
d = dict(Counter(in_arr))
m = max(d.values())
if m // g * g == m:
    cnt_b = m // g
else:
    cnt_b = m // g + 1
print (cnt_b * g * len(d.keys()) - cnt)
