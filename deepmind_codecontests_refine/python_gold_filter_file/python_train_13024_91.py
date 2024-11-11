import math
n, m = map(int, input().split())
a = math.modf(m/n)

if n > m:
    print(1)
elif a[0] > 0:
    print((m//n)+1)
else:
    print(m//n)
