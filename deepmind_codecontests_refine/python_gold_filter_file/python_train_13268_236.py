n = int(input())
rs = 0
for i in range(n):
    p, q = map(int, input().split())
    if q - p >= 2:
        rs += 1
print(rs)