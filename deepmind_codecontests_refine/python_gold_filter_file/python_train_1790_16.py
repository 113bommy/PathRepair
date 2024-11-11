n = int(input())
for i in range(n):
    a = int(input())
    if a == 0:
        print(4)
    elif a == 1:
        print(3)
    elif a == 2:
        print(2)
    elif a == 3:
        print(1)
    elif a % 2 !=0:
        print(1)
    else:
        print(0)
