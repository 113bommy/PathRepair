n = int(input())
count = 0
for i in range(n):
    x = list(map(int, input().split()))
    if (x[0] == 1 and x[1] == 1 and x[2] == 1)\
            or (x[0] == 1 and x[1] == 1 and x[2] == 0) \
            or (x[0] == 1 and x[1] == 0 and x[2] == 1) \
            or (x[0] == 0 and x[1] == 1 and x[2] == 1):
        count += 1
print(count)
