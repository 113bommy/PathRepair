n = int(input())
for i in range(n):
    a = int(input())
    print(a//7 + (1 if (a%7) else 0))