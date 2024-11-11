k, s = map(int, input().split())
print(sum(0 <= s - (x + y) <= k for y in range(k + 1) for x in range(k + 1)))
