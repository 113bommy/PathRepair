n = int(input())
i1 = i2 = -1
i = 0
for x in map(int, input().split()):
    i += 1
    if (x == 1) or (x == n):
        if i1 < 0:
            i1 = i
        else:
            i2 = i
if (i1 - 1) <= (n - i2):
    print(n - i1)
else:
    print(i2-1)
