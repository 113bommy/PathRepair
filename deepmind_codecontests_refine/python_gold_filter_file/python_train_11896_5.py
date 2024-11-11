n, d, m = map(int, input().split())
a = [*map(int, input().split())]

ba, sa = [*filter(lambda x: x > m, a)], [*filter(lambda x: x <= m, a)]

ba.sort(reverse=True)
sa.sort()

from itertools import accumulate

aba = [*accumulate(ba)]
asa = [0] + [*accumulate(sa)]

ans = asa[-1]

for i in range(len(aba)):
    j = max(0, i * d - (len(aba) - i - 1))
    if j < len(asa):
        ans = max(ans, aba[i] + (asa[-1] - asa[j]))

print(ans)