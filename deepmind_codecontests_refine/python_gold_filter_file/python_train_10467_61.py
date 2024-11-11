import sys
input = sys.stdin.readline().strip

n = input()

print(n + n[::-1])
