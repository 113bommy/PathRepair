l, r = map(int, input().split())
print(sum(l <= 2 ** i * 3 ** j <= r for i in range(31) for j in range(20)))
