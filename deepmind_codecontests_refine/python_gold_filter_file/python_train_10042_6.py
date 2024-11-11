
import math

n = int(input())
i = 1
while n > 0:
    n -= i
    i += 1
print('YES' if n == 0 else 'NO')
