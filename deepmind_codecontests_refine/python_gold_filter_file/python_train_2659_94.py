n, h = map(int, input().split())
l = list(map(int, input().split()))
r = 0
for i in l:
    if i > h:
        r += 2
    else:
        r += 1
print(r)