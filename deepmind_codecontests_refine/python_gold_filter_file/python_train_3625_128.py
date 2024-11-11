s = input()
if s[0] == 'A' and s[2:-1].count('C') == 1 and sum(_==_.upper() for _ in s)==2:
    print('AC')
else:
    print('WA')
