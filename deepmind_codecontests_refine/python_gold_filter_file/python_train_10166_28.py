p, y = map(int, input().split())
for x in range(y - (y & 1 ^ 1), p, -2):
    if x & 1 and all(x % i for i in range(3, min(int(x ** .5), p) + 1, 2)):
        print(x)
        exit()
print(-1)
