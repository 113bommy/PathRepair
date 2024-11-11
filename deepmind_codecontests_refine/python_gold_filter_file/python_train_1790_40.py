q = int(input())

for i in range(q):
    n = int(input())
    if n == 1:
        print(3)
    elif n == 2:
        print(2)
    elif n == 3:
        print(1)
    elif n % 2 == 0:
        print(0)
    else:
        print(1)