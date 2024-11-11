from math import *
m = int(input())
n = int(input())
a = list(str(n))
count = 0
for i in range(m):
    if int(a[i]) % 2 == 0:
        count += (i+1)
print(count)