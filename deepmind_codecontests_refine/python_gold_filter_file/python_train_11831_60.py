a = input()
count = 0
b = ['a', 'o', 'e', 'i', 'u', '1', '3', '5', '7', '9']
for i in a:
    if i in b:
        count += 1
print(count)