import re
S = input()
print('AC' if S.startswith('A') and (S[2:-1]).count('C') == 1 and len(re.findall('[A-Z]', S)) == 2 else 'WA')
