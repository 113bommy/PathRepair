T = int(input())
count = 0
for _ in range(T):
    p, q = map(int, input().split())
    if q - p >= 2:
        count += 1
print(count)