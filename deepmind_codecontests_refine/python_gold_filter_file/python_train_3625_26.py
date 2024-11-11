import re
s = input()
c = r'A[a-z]+C[a-z]+$'
print('AC' if re.match(c,s) else 'WA')