n, x = map(int, input().split())
count = x
dist = 0
for i in range(n):
    d = list(input())
    if d[0] == '+':
        count += int(''.join(d[2:]))
    if d[0] == '-':
        if int(''.join(d[2:])) > count:
            dist += 1
        if int(''.join(d[2:])) <= count:
            count -= int(''.join(d[2:]))

print(count, dist)