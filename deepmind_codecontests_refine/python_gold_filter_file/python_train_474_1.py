from math import ceil
n, k = map(int, input().split())
a = list(map(int, input().split()))
s = 0
for i in a:
    b = ceil(i / k)
    s = s + b
print(ceil(s / 2))