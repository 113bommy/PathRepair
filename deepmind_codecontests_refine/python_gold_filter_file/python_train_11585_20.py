import math
t = int(input())
for tests in range(t):
    a, b = [int(x) for x in input().split()]
    print(math.ceil(abs(b - a) / 10))