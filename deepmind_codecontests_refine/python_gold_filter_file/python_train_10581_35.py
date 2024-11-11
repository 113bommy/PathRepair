# import os

n, m = map(int,input().split())

market = []
r = 99999999999
for _ in range(n):
    a,b = map(int, input().split())
    market.append([a,b])
    p = a/b
    r = a/b if a/b < r else r
print(r*m)