from math import log
a, b = map(int, input().split())
print(int(log(b/a)/log(1.5)) + 1)