N = int(input())
print(sum([i if i % 3 > 0 and i % 5 > 0 else 0 for i in range(N + 1)]))