buoi = input()
a, b = 0, 0
for i in buoi:
    if i.islower():
        a += 1
    elif a > 0:
        b += 1
        a -= 1
print(b)
