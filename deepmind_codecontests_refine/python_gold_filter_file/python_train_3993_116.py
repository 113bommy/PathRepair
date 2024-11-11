from math import ceil
n,m,a = map(int, input().split())
print(ceil(m/a) * ceil(n/a))