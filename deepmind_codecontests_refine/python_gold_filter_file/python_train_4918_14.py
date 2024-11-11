import sys
input = sys.stdin.readline

s = "abcdefghijklmonpqrstuvwxyz"
for _ in range(int(input())):
    n, a, b = map(int, input().split())
    st = s[:b]*n
    print(st[:n])
