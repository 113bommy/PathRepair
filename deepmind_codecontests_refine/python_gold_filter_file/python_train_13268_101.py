n = int(input())
sum = 0
for _ in range(n):
    p, q = map(int, input().split())
    if q-p >= 2:
        sum += 1
print(sum)