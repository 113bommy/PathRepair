n = int(input())
x = n // 2
print(x)
if n % 2 == 0:
    while x:
        print(2, end=" ")
        x -= 1
else:
    while x - 1:
        print(2, end=" ")
        x -= 1
    print(3, end="")