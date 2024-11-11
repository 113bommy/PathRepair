n, k = map(int, input().split())

x = 0
for i in input().split():
    if i.count('4') + i.count('7') <= k:
        x += 1

print(x)
