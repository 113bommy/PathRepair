from sys import stdin
input = stdin.readline

n = int(input())
if n % 2 > 0:
    print(0)
else:
    print(n // 4 - (n % 4 == 0))