N, A = int(input()), list(map(int, input().split()))
C = [a // 400 for a in A]
mini = sum([1 for c in range(8) if c in C])
print(max(mini, 1), mini + sum([1 for c in C if c >= 8]))
