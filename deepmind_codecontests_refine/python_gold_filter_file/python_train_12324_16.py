y = 0
x = 0
n = int(input())
for i in range(n):
    a = str(input())
    if a == '++X' or a == 'X++':
        y = y + 1
    elif a == '--X' or a == 'X--':
        x = x - 1

print(x+y)

