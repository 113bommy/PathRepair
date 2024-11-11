import math
a, b = [int(i) for i in input().split()]
n = int(input())
ans = -1

for i in range(n):
    x, y, v = [int(i) for i in input().split()]
    num1 = a - x
    num2 = b - y
    time = math.sqrt(num1 * num1 + num2 * num2)
    time /= v
    if ans != -1 and ans > time:
        ans = time
    elif ans == -1:
        ans = time

print(ans)