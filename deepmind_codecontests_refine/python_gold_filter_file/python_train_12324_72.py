n = int(input())
x = 0
y = [input() for z in range(n)]
for z in y:
    if z == "X++" or z == "++X":
        x += 1
    elif z == "X--" or z == "--X":
        x -= 1
print(x)
