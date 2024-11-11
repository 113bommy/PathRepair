import math
t = int(input())
a = 1
for t0 in range(t):
    n = int(input())
    N = 2 * n
    if n % 2 == 1:
        diag = 2 * (math.cos(math.pi / N) - math.sin(math.pi / N)) + a / math.sin(math.pi / N)
        stor = diag / (2 ** 0.5)
    if n % 2 == 0:
        stor = 2 * (((1 / (2 - 2 * math.cos(2 * math.pi / N))) - 1/4) ** 0.5)
    print(stor)
