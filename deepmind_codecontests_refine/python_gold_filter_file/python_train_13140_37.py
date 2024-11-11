import sys

input = lambda: sys.stdin.readline().rstrip()

for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(*sorted(a)[::-1])