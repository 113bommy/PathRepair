n = int(input())
x = 0
for i in range(n):
    op = input()
    if op == "X++" or op == "++X":
        x += 1
    if op == "X--" or op == "--X":
        x -= 1
print(x)