k = int(input())
print(3, 4)
inf = 2 ** 18 - 1
x = inf ^ k
y = inf >> 1
pattern = [
        [inf, inf, inf, 0],
        [inf, 0,   y,   0],
        [inf, x,   inf, y]
        ]
for i in range(3):
    print(*pattern[i])
