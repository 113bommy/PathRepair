n, m = [int(c) for c in input().split()]
field = []

for i in range(n):
    field.append([int(c) for c in input().split()])

min = n
s = 1

while min > 0 and min % 2 == 0 and s:
    t = field[min // 2 : min]
    t.reverse()
    if field[:min // 2] == t:
        min = min // 2
    else:
        s = 0

print(min)