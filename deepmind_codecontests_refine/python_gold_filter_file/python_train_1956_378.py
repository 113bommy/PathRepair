n, k = map(int, input().split())
l = n%k
print(min(l, k-l))