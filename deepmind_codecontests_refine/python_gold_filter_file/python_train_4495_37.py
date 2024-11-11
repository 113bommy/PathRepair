a = input()
b = ''
for i in a:
    if i.lower() not in ['a','e','i','o','u','y']:
        b+='.'+i.lower()
print(b)
