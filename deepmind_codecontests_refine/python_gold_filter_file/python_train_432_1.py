import math
n = int(input())
a = list(map(int, input().split()))
x = max(a)
total = 0
k = 0
for i in a:
    total += x-i
    k = math.gcd(k, total)
print(total//k, k)