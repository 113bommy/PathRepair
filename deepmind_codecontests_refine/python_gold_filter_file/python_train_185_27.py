import math
N, P = map(int, input().split())

for i in reversed(range(1, round(math.pow(P, 1 / N)) + 1)):
    if P % (i ** N) == 0:
        print(i)
        exit()