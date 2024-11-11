from bisect import bisect_right
from collections import Counter

n = int(input())
a = list(map(int, input().split()))

power = 1
powers = [1]
while power <= 10 ** 9:
    power *= 2
    powers.append(power)

a.sort()
c = Counter(a)

ans = 0
for e in a[::-1]:
    i = bisect_right(powers, e)
    target = powers[i]

    if target == 2 * e:
        if c[e] >= 2:
            c[e] -= 2
            ans += 1

    else:
        if c[e] and c[target-e]:
            c[e] -= 1
            c[target-e] -= 1
            ans += 1

print(ans)
