import re
s=input()
print('AC' if re.match(r'^A[a-z]+C[a-z]+$',s) else 'WA')
