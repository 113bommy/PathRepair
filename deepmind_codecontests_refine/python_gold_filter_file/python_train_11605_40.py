import sys

a, m = map(int, input().split())

d = set()
for i in range(10**7):
    d.add(a%m)
    a += a%m
    if a%m == 0:
        print('Yes')
        sys.exit(0)
    if a%m in d:
        print('No')
        sys.exit(0)