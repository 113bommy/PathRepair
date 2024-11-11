N = int(input())
count = 0
for i in range(N):
    p, q = [int(x) for x in input().split()]
    if q - p >= 2:
        count += 1
print(count)
