a, b = map(int, input().split())
for i in range(a, a-b, -1):
    print(i, end = " ")
for i in range(1, a-b+1):
    print(i, end=" ")