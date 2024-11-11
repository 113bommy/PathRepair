n = int(input())
x = 0
for i in range(n):
    a, b = map(int,input().split())
    if a <= b - 2:
        x += 1
print(x)