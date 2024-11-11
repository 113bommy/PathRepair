a, b, k = map(int, input().split())
print([j for j in [i for i in range(1, 101) if a % i == 0] if b % j == 0][-k])