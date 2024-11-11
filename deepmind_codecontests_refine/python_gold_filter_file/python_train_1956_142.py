n, k = map(int, input().split())
print(min(abs(-n%k), n%k))