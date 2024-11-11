n, k = map(int, input().split())
t = k // n
print(t + (1 if k != t*n else 0))
