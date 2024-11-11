n, h = map(int, input().split())
a = list(map(int, input().split()))
j = 0
for i in a:
    if i > h:
        j += 2
    else:
        j += 1
print(j)
