import sys, re

n = int(sys.stdin.readline())
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
for i in range(10000001):
    if (n - a * i) % b == 0 and (n - a * i) >= 0:
        print('YES')
        print(i, (n - a * i) // b)
        sys.exit(0)
print('NO')
