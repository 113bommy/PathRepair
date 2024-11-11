word = input()

low_count = len([c for c in word if c.islower()])

if (2*low_count < len(word)):
    print(word.upper())
else:
    print(word.lower())
