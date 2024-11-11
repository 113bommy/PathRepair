n, x, y = map(int, input().split(" "))
digits = input()
res = 0
for i in range(n-x, n):
    if i == (n-y-1):
        if digits[i] == "0":
            res += 1
    else:
        if digits[i] == "1":
            res += 1
print(res)
