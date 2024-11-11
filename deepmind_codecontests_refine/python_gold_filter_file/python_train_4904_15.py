n = int(input())


def gcd(a, b):
    while True:
        if a == 0:
            return b
        elif b == 0:
            return a

        if a >= b:
            a = a % b
        elif b > a:
            b = b % a


s_1 = [el for el in range(1, n + 1) if el % 2 == 0]
s_2 = [el for el in range(1, n + 1) if el % 2 != 0]

if gcd(sum(s_1), sum(s_2)) > 1:
    print("Yes")
    print(len(s_1), *s_1)
    print(len(s_2), *s_2)
else:
    print("No")
