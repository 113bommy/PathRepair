n = int(input())
if n % 2 == 1:
    print(-1, end=' ')
else:
    for i in range(n, 0, -1):
        print(i, end=' ')
