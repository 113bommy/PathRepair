[n, k] = list(map(int, input().split()))
print(min(1, n-k,k),min(n-k, 2*k))