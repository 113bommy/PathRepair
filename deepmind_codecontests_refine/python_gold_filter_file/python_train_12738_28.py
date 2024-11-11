n = int(input())
if n % 2 == 0:
    for x in range(1, n, 2):
        print(x + 1, x, end = " ")
else:
    print(-1)