n,k = map(int, input().split())
n = n%k
print(min(abs(n-k), n))