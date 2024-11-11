"""B - Fox Dividing Cheese"""

a, b = map(int, input().split())

div = [2, 3, 5]
op = 0
if a >= 1 and b <= 1E+10:
    if a == b:
        print(op)
    else:
        for i in div:
            while a % i == 0 and b % i == 0:
                a = a / i
                b = b / i
            while a % i == 0:
                a = a / i
                op += 1
            while b % i == 0:
                b = b / i
                op += 1
        if a == b:
            print(op)
        else:
            print(-1)
else:
    print("Error")



