n = int(input())
s = input()
high = 1
max_high = 1
for i in range(1, n):
    if s[i] == '[':
        high += 1
    else:
        if high > max_high:
            max_high = high
        high -= 1
high = max_high
lenght = 1
for i in range(1, n):
    if s[i] == s[i - 1]:
        lenght += 1
    elif s[i] == ']' and s[i - 1] == '[':
        lenght += 4
    else:
        lenght += 1
Map = []
high = high * 2 + 1
for i in range(high):
    Map.append(dict())
    for j in range(lenght):
        Map[i][j] = ' '

highs = [high]
xs = [0]
h = high
x = 0
for i in range(1, n):
    if s[i] == s[i - 1]:
        if s[i] == ']':
            h += 2
        else:
            h -= 2
        x += 1
    elif s[i] == ']' and s[i - 1] == '[':
        x += 4
    else:
        x += 1
    highs.append(h)
    xs.append(x)


def s_create(x, h, side):
    if side == ']':
        Map[(high - h) // 2][x - 1] = '-'
        Map[(high - h) // 2][x] = '+'
        Map[high - (high - h) // 2 - 1][x - 1] = '-'
        Map[high - (high - h) // 2 - 1][x] = '+'
    else:
        Map[(high - h) // 2][x + 1] = '-'
        Map[(high - h) // 2][x] = '+'
        Map[high - (high - h) // 2 - 1][x + 1] = '-'
        Map[high - (high - h) // 2 - 1][x] = '+'
    for i in range(h - 2):
        Map[(high - h) // 2 + i + 1][x] = '|'
last_h = high
s_create(0, high, '[')

for i in range(1, n):
    s_create(xs[i], highs[i], s[i])
for i in range(high):
    for j in range(lenght):
        print(Map[i][j], end='')
    print()