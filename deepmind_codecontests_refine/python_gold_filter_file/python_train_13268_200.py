num = int(input())
count = 0
while num != 0:
    p, q = map(int, input().split())
    if q-p >= 2:
        count += 1
    num -= 1
print(count)