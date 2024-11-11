n = int(input())
if n % 4 == 2:
    print(1, 'B')
else:
    print((5 - n % 4) % 4, 'A')
