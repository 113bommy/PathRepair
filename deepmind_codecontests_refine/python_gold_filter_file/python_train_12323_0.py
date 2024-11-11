import re

for _ in range(8):
    if re.search('WW|BB', input()) is not None:
        print('NO')
        exit()
print('YES')
