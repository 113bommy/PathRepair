n = int(input())
m = 10**9 + 7
r = 1
for i in range(1, n+1):
    r = (r * i) % m
print((r - (2**(n-1)%m)) % m)