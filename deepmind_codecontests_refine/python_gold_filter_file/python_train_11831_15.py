s = input()
res = 0

for char in s:
    if (char in ('a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9')):
        res += 1

print(res)