from sys import exit

n, k = map(int, input().split())
if k == 0:
    print(0, 0)
else:
    print(min(1, n - k), min(2 * k, n - k))
