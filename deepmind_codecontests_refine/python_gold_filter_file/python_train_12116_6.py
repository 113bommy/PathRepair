import sys


# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

input = sys.stdin.readline

a, b= map(int,input().split())

if a == b:
    print(0)

else:
    x = a ^ b
    c = 1

    while x:
        x >>= 1
        c <<= 1

    print(c-1)