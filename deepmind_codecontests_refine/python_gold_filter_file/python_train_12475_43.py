n, a, b = [int(i) for i in input().split()]
print(["Alice", "Borys"][(a - b) % 2])