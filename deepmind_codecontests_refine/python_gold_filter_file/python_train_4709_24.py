s = input()

if len(s) == 1:
    if s.isupper():
        print(s.lower())
    else:
        print(s.upper())

elif s[0].islower() and s[1:].isupper():
    first_letter = s[0].upper()
    last_part = s[1:].lower()
    print(first_letter + last_part)

elif s.isupper():
    s = s.lower()
    print(s)

else:
    print(s)
