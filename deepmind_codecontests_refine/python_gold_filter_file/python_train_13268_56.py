n = int(input())
counter = 0
for i in range(n):
    p, q = map(int, input().split())
    if q - p >= 2:
        counter += 1
print(counter)
