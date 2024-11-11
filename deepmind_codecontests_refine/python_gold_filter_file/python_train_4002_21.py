s = input()
le, se, dig = False, False, False

for i in s:
    o = ord(i)

    if 48 <= o <= 57:
        dig = True
    if 65 <= o <= 90:
        le = True
    if 97 <= o <= 122:
        se = True
    if le and se and dig:
        break

print('Correct' if le and se and dig and len(s) >= 5 else 'Too weak')
