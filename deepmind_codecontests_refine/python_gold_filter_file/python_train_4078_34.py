# import sys

# sys.stdin = open("input.txt", "r")
# sys.stdin = open("output.txt", "w")

a, b = map(int, input().split())

print((2 ** a * 2 ** b) % 998244353)