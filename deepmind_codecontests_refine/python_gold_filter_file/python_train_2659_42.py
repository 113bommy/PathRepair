n, h = map(int, input().split())
l = list(map(int, input().split()))
o = 0
for i in l:
    if i > h:
        o += 2
    else:
        o += 1
print(o)
