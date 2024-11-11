a = int(input())
res = 0
while a > 0:
    if (a % 8 == 1):
        res += 1
    a //= 8
print(res)