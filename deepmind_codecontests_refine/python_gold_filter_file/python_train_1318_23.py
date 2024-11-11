s = input()
if s.count('o') == 0 or s.count('-') % s.count('o') == 0:
    print('yes')
else:
    print('no')
    
