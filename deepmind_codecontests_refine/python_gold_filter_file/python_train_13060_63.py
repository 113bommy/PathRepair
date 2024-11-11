x = int(input())

a = x // 2
b = x - (x // 2)

if x % 2 == 0:
    print(f"{x - 4} {4}")
else:
    print(f"{x - 9} {9}")
