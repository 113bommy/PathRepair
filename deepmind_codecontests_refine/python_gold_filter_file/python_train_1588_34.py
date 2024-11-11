from sys import stdin, stdout
import math


def main():
    # t = 1
    t = int(input())
    for i in range(t):
        n = int(input())
        n *= 2
        a = 1
        big_r = a / (2 * math.tan(math.pi / n))
        print(big_r * 2)


main()
