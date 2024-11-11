n, h = map(int, input().split())
a = list(map(int, input().split()))

k = 0
for i in a:
    if i > h:
        k += 2
    else:
        k += 1
print(k)
