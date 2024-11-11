string = input()
result = ''
for char in string:
    if char.lower() in 'aoyeui':
        continue
    else:
        result += '.' + char.lower()
print(result)