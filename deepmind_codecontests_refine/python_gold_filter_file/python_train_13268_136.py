n = int(input())
rooms = 0
for i in range(n):
    p, q = list(map(int, input().split(" ")))
    if q - p > 1:
        rooms += 1
print(rooms)