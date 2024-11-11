n = int(input())
capacity = 0
for p in range(n):
    x, y = [int(i) for i in input().split()]
    if x < y-1:
        capacity += 1
    else:
        capacity += 0
print(capacity)