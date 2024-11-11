n = int(input())
x = 0
for i in range(n):
    opr = str(input())
    if '+' in opr:
        x += 1
    else:
        x = x - 1
print(x)