from math import gcd
n = int(input())
l = [int(i) for i in input().split(" ")]

x = l.count(1)

result = 10e9 + 5
if x > 0:
    print(n - x)
    exit(0)
for L in range(n - 1):
    temp = l[L]
    for R in range(L + 1, n):
        temp = gcd(temp, l[R])
        if temp == 1:
            r = R - L
            result = min(result, r)
if result == 10e9 + 5:
    print(-1)
else:
    print(n + result - 1)