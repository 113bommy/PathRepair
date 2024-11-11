k = int(input().strip())

print("2 3")
print("{} {} {}".format((2 << 16) + k, k, 0))
print("{} {} {}".format(2 << 16, (2 << 16) + k, k));