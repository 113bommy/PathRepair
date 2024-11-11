n, k = map(int, input().split())

print(str(min(1, n-k, k)) + " " + str(min(2*k, n-k)))
