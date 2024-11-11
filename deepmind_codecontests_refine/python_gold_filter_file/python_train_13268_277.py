n = int(input())
rooms = 0
for x in range(n):
    a, b = list(map(int, input().split(" ")))
    if b - a >= 2:
        rooms += 1
print(rooms)
