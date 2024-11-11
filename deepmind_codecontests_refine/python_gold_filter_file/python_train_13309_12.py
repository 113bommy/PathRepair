n = int(input())
array = list(map(int, input().split()))

total = 0
flag = -1
minus = 0
for tmp in range(len(array)):
    total += array[tmp]
    if total * flag <= 0:
        minus += abs(total*flag)+1
        total = flag
    flag *= -1

total = 0
flag = 1
plus = 0
for tmp in range(len(array)):
    total += array[tmp]
    if total * flag <= 0:
        plus += abs(total*flag)+1
        total = flag
    flag *= -1

print(min(minus, plus))