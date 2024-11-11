import re
input()
print(len("".join(re.split('00+', input().replace(' ', '').strip('0')))))