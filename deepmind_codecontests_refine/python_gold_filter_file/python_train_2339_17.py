f = input()
m = input()
s = input()

if m != s and f != s and f != m:
    r = '?'
    
elif m == s:
    if m == 'rock':
        if f == 'paper':
            r = 'F'
        else:
            r = '?'

    elif m == 'scissors':
        if f == 'rock':
            r = 'F'
        else:
            r = '?'

    else:
        if f == 'scissors':
            r = 'F'
        else:
            r = '?'

elif f == s:
    if f == 'rock':
        if m == 'paper':
            r = 'M'
        else:
            r = '?'

    elif f == 'scissors':
        if m == 'rock':
            r = 'M'
        else:
            r = '?'

    else:
        if m == 'scissors':
            r = 'M'
        else:
            r = '?'

else:
    if m == 'rock':
        if s == 'paper':
            r = 'S'
        else:
            r = '?'

    elif m == 'scissors':
        if s == 'rock':
            r = 'S'
        else:
            r = '?'

    else:
        if s == 'scissors':
            r = 'S'
        else:
            r = '?'

print(r)
