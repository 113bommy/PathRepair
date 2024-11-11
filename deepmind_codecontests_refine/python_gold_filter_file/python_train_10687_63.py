num, n = map(int, input().split())
for i in range(n):
    if num % 10 == 0:
        num //= 10
    else:
        num -= 1
print(num)
