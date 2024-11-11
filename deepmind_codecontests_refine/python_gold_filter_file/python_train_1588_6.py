from math import sin, radians

for _ in range(int(input())):
    n = int(input()) * 2

    print(1 / (2 * sin(radians(90/n))))