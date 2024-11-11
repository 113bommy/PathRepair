N = int(input())
print(sum(x for x in range(1, N+1) if x % 3 != 0 and x % 5 != 0))