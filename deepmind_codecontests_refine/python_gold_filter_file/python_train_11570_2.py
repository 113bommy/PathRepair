n = int(input())
for item in range(n):
    a = int(input())
    if a <= 7:
        print(1)
    else:
        if a % 2 == 0:
            print(a //2)
        else:
            print(((a - 2)//2) + 1)
