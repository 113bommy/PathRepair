# len > 5, lower, UPPER, number
p = input()
if len(p) < 5:
    print('Too weak')
    exit()
lower = 'abcdefghijklmnopqrstuvwxyz'
upper = lower.upper()
digit = '1234567890'
for check in [lower, upper, digit]:
    valid = False
    for l in check:
        if l in p:
            valid = True
            break
    if not valid:
        print('Too weak')
        exit()
print('Correct')

