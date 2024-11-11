n = int(input())
c = 0
for i in range(n):
    n, q = map(int, input().split())
    if q - n >= 2:
        c += 1
print(c)
