n = int(input())

if n%4 == 0:
    n += 1
    print(1, "A")
elif n%4 == 2:
    n += 1
    print(1, "B")
elif n%4 == 3:
    n += 2
    print(2, "A")
elif n%4 == 1:
    print(0, "A")