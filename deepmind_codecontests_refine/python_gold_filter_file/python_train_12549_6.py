import sys

n = int(input())
a = list(map(int, input().split()))
print('YES' if a.count(0) == (1 if n > 1 else 0) else 'NO')
