import sys
import math

# sys.stdin = open("in.txt")
for _ in range(int(input())):
    n, m = map(int, input().split())

    li = list(map(int, input().split()))
    if n == 2 or n > m:
        print(-1)
        continue
    if li[0] < li[1]:
        min1 = 0
        min2 = 1
    else:
        min1 = 1
        min2 = 0
    for i in range(2, n):
        if li[i] < li[min1]:
            min2 = min1
            min1 = i
        elif li[i] < li[min2]:
            min2 = i
    print(sum(li) * 2 + (m - n) * (li[min1] + li[min2]))
    for i in range(n):
        print(i + 1, (i + 1) % n + 1)
    for i in range(m - n):
        print(min1 + 1, min2 + 1)