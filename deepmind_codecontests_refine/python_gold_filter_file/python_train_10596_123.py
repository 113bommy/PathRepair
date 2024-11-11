n, k  = map(int, input().split())

i = 1
while n >= k**i:
    i += 1

print(i)