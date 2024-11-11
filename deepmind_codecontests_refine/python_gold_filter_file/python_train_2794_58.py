x, a, b = map(int, input().split())
print(["B", "A"][abs(x - a) < abs(x - b)])