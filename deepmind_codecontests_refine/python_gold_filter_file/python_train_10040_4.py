import math


def main_function():
    n, m = [int(i) for i in input().split(" ")]
    groups = [int(i) for i in input().split(" ")]
    counter = 1
    current_bus = 0
    for i in groups:
        if current_bus + i <= m:
            current_bus += i
        else:
            counter += 1
            current_bus = i
    print(counter)


main_function()