A, B, K = map(int, input().split())

print("{} {}".format(max(0, A-K), max(min(B+A-K, B),0)))
