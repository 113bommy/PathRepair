# coding=utf-8
import math


def square(number: float) -> float:
    return number * number


if __name__ == '__main__':
    N = int(input())
    for i in range(N):
        xa, ya, ra, xb, yb, rb = map(float, input().split())
        distance = math.sqrt(square(xb - xa) + square(yb - ya))
        if distance > (ra + rb):
            print(0)
        elif distance >= math.fabs(ra - rb):
            print(1)
        elif distance < math.fabs(ra - rb):
            if ra > rb:
                print(2)
            elif ra < rb:
                print(-2)
        else:
            pass