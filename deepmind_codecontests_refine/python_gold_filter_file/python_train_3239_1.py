import math
n, m = map(int, input().split())
if m == 0:
    print(n, n)
    exit(0)
otv1 = n - m * 2
if otv1 < 0:
    otv1 = 0
otv2 = (1 + math.sqrt(1 + 8*m)) / 2
if otv2%1 != 0:
    otv2= otv2//1 + 1
otv2 = int(n - otv2)
if otv2 < 0:
    otv2 = 0
print(otv1, otv2)