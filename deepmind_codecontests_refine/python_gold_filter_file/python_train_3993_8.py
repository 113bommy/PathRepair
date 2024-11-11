from math import ceil

n,m,s = map(int, input().split())

print(ceil(n/s) * ceil(m/s))
