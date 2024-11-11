x, y, l, r = map(int, input().split())
ul = [l - 1, r + 1]

i = 1
while i < r:
    j = 1
    while i + j < l:
        j *= y
    while i + j <= r:
        ul.append(i + j)
        j *= y
    i *= x

ul.sort()
maxd = max(ul[i] - ul[i - 1] for i in range(1, len(ul)))
print(maxd - 1)
