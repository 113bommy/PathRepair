a = input()
alp = 'abcdefghijklmnopqrstuwvxyz'
b = ''
for i in a:
    if i not in b and  i in alp:
        b += i
print(len(b))
