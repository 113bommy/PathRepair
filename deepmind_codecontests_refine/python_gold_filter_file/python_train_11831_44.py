s = input()
c = 0
for i in s:
    if i in ('a', 'e', 'i', 'o', 'u'):
        c += 1
    elif i in ('1', '3', '5', '7', '9'):
        c += 1
print(c)
