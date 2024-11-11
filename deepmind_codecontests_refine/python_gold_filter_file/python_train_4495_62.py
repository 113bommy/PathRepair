s = input()

abc = 'bcdfghjklmnpqrstvwxz'
abc_V = 'BCDFGHJKLMNPQRSTVWXZ'
r = ''

for item in s:
    if item in abc:
        r += '.'
        r += item

    elif item in abc_V:
        r += '.'
        r += item.lower()

print(r)
        
