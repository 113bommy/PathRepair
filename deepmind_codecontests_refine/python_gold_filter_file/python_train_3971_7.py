vowels = 'aiueo'

s = input()
t = input()

if len(s) != len(t):
    print('No')
else:
    for i, j in zip(s, t):
        if (i in vowels and j not in vowels) or \
        (i not in vowels and j in vowels):
            print('No')
            exit()
    print('Yes')
