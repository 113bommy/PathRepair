n = int(input())

colors = [0] * 13
for i in list(map(int, input().split())):
    colors[i//400] += 1

ans = 8 - colors[:8].count(0)
free = sum(colors[8:])

print(max(1, ans), max(1, ans + free))