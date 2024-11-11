# import sys

# # Remove these 2 lines while submitting your code online
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')
n = int(input())

x = set(input().split()[1:])
y = set(input().split()[1:])

x.discard('0')
y.discard('0')

print('I become the guy.' if len(x | y) >= n else 'Oh, my keyboard!')
