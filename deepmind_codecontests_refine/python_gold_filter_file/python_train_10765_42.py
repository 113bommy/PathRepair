s = str(int(input()))
for i in range(len(s) - 1, -1, -1):
    snew = ''
    x = int(s[i])
    if x >= 5:
        snew += '-O|'
    else:
        snew += 'O-|'
    snew += 'O' * (x % 5)
    snew += '-'
    snew += 'O' * (4 - x % 5)
    print(snew)
