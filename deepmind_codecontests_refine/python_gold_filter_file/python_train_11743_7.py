n = int(input())
for i in range(n - 1):
    for j in range(i + 1, n):
        print(((i ^ j) &- (i ^ j)).bit_length(), end=" ")
    print()