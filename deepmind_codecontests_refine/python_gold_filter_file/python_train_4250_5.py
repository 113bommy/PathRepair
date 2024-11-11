A, B, K = map(int, input().split())
print([i for i in range(1, 101) if A % i + B % i < 1][-K])