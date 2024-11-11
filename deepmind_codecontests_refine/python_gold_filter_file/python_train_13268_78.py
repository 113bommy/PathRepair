n = int(input())
count = 0
for i in range(n):
    p, q = map(int, input().split())
    p += 2
    if p <= q:
        count += 1

print(count)