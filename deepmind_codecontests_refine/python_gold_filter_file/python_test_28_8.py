from math import ceil

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print((a + 2 * b + 3 * c) % 2)
