from collections import defaultdict
N = int(input())
twofive = defaultdict(int)
for i in range(N):
    a = round(float(input()) * (10**9))
    b = 0
    c = 0
    while a % 2 == 0 and b < 18:
        b += 1
        a //= 2
    while a % 5 == 0 and c < 18:
        c += 1
        a //= 5
    twofive[(b, c)] += 1
ans = 0
for b, c in twofive.keys():
    for d, e in twofive.keys():
        if b + d >= 18 and c + e >= 18:
            if (b, c) != (d, e):
                ans += twofive[(b, c)] * twofive[(d, e)]
            else:
                ans += twofive[(b, c)] * (twofive[(b, c)] - 1)
print(ans//2)
