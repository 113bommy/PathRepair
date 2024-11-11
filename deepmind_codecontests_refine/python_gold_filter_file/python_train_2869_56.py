n = int(input(''))
for i in range(n):
    x = str(input(''))
    if len(x) <= 10:
        print(x)
    else:
        print(x[0], len(x) - 2, x[-1], sep = '')