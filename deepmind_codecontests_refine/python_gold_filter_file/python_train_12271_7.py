n = int(input())
for i in range(n):
    a, b, c = sorted(list(map(int, input().split())))
    if c ** 2 == (a ** 2 + b ** 2):
        print("YES")
    else:
        print("NO")