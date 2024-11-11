n = int(input())
a = list(map(int, input().split()))
free = 0
color = set()
for i in a:
    if i >= 3200:
        free += 1
    else:
        color.add(i//400)
print(max(1, len(color)), len(color) + free)