n = int(input())
str = input()
s = "yeuaoi"
i = 1
while i < n:
    if str[i - 1] in s and str[i] in s:
        str = str[:i ] + str[i + 1:]
        n -= 1
        i -= 1
    i += 1
print(str)
