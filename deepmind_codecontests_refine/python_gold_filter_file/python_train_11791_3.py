from math import *

str = 'codeforces'
# a, b, n = map(int, input().split())
eps = 1e-14
k = int(input())
k = float(k)
s = 10.0
x = floor(pow(k, 1.0 / s))
p = log2((x + 1.0) ** s / k) / log2((x + 1.0) / x)
p = int(p + eps)
x = int(x)

for i in range(p):
    for times in range(x):
        print(str[i], end='')
for i in range(p, int(s)):
    for times in range(x + 1):
        print(str[i], end='')
print()
