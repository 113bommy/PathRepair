n = (int(input()))
x = 0
for i in range(0,n):
    op = input()
    if op ==  "X++" or op == "++X":
        x += 1
    elif op ==  "X--" or op == "--X":
        x -= 1
print(x)