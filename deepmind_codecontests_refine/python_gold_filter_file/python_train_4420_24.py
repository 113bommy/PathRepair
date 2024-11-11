letter = set(input().replace(' ', '').strip('{} ').split(','))

if letter == {''}:
    print(0)
else:
    print(len(letter))