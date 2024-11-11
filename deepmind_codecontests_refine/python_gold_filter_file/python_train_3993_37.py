from math import ceil
n, m, a = map(int, input().split())
print(str(ceil(n/a)*ceil(m/a)))
