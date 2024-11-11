# Author: Uday Gupta
import sys

input = sys.stdin.readline

t = int(input())

for test in range(t):
    n = int(input())
    #a = list(map(int, input().split()))
    if n == 1:
        print(1)
    elif n == 2:
        print(1)
    elif n == 3:
        print(2)
    elif n % 2 == 0:
        print(int(n / 2))
    else:
        print(int((n-1)/2) + 1)
    
    