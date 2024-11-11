n, h = map(int, input().split())
a = list(map(int, input().split()))

n = 0
for i in a:
    if i > h:
        n += 2
    else:
        n += 1
print(n)
