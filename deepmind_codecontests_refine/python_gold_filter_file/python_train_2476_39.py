a, b, c, d = map(int, input().split())


if -(-a // d) >= -(-c // b):
    print("Yes")
else:
    print("No")