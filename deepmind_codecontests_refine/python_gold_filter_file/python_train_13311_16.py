from math import ceil

n = int(input())
x = 100
for i in range(n): x = ceil(x * 1.05)
print(x * 1000)