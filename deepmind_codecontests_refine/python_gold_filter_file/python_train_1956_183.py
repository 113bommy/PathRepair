N, K = list(map(int, input().split()))
print(min(N%K, K-(N%K)))