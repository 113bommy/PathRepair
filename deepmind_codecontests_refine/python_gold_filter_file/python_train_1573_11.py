def min_boxes(n):
    if n == 0:
        return 0
    return len(bin(n)[2:])

print(min_boxes(int(input())))