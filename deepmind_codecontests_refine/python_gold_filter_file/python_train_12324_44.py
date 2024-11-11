n = int(input())
x = 0
for i in range(n):
    if input()[1] == "+":
        x += 1
    else:
        x -= 1
print(x)