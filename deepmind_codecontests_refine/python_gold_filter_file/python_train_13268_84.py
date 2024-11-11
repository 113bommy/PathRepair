n = int(input())
m = 0
for i in range(n):
    p, q = map(int, input().split())
    if q - p >= 2:
        m += 1
print(m)
