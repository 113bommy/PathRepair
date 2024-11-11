n, k = map(int, input().split())
p = n%k
print(min(p, k-p))