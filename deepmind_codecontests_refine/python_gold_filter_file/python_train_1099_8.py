n = int(input())
if n == 0:
    print(1)
else:
    print((8 ** ((n - 1) % 4 + 1)  % 10))