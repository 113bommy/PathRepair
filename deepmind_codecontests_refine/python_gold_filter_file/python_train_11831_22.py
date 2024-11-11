import re

s = input().lower()

s = re.sub("[^aeuio13579]", '', s)
print(len(s))