import math
n = int(input())
if n <= 2:
    print("No")
    exit()
s = n * (n + 1) // 2
for i in range(2, n + 1):
    if math.gcd(i, s - i) > 1:
        x = i
        break
print("Yes")
print(1, x)
print(n - 1, end=" ")
for i in range(1, n + 1):
    if i != x:
        print(i, end=" ")