n = int(input())
a = [0] + sorted(list(map(int, input().split())))

if n % 2 == 0:
    print(a[n // 2])
else:
    print(a[(n // 2) + 1])