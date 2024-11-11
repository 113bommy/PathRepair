n = int(input())
for i in '"' * n:
    n = int(input())
    print(max(4 - n, n % 2))