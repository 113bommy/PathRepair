__author__ = 'asmn'

n = int(input())
a = sorted(map(int, input().split()))
dt = int(input())

ans, l, r = 0, 0, 0
while r < len(a):
    while r < len(a) and a[r] - a[l] <= dt:
        r += 1
    ans = max(ans, r - l)
    l += 1

print(ans)