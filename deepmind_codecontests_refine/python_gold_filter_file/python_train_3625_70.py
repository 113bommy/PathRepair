import re

ptn = re.compile(r'A[a-z]+C[a-z]+')
print('AC' if re.fullmatch(ptn, input()) else 'WA')
