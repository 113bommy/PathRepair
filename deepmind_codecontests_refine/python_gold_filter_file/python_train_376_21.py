def get_sum(end):
    if end == 0:
        return 0
    return (1 + end) * end / 2


i1 = int(input())
i2 = int(input())

a1 = min(i1, i2)
a2 = max(i1, i2)
m = (a1 + a2) // 2

res1 = get_sum(m - a1)
res2 = get_sum(a2 - m)

print(int(res1 + res2))
