import sys


# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

input = sys.stdin.readline


t = 1

while t:
    t -= 1

    n = int(input())
    s = input()

    res = 1
    for i in range(1, n):
        res += (1 if s[i] != s[i-1] else 0)
    print(min(n, res+2))



    