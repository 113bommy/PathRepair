n, k = map(int, input().split())
x = 1
while n >= k**x:
    x += 1
print(x)