n, k = map(int, input().split())

s = n % k 
print(min(s, k-s))