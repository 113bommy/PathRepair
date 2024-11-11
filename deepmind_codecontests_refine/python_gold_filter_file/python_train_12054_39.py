N = int(input())
print(sum(x for x in range(N + 1) if x % 3 != 0 and x % 5 != 0))