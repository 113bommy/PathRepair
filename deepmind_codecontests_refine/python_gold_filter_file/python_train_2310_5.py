s = input()

min_char = 'z'
for letter in s:
    if letter <= min_char:
        print('Mike')
    else:
        print('Ann')
    min_char = min(min_char, letter)
