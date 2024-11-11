import re

s = input()
test = re.match(r"^A[a-z]+C[a-z]+$", s)
if test:
    print('AC')
else:
    print('WA')
