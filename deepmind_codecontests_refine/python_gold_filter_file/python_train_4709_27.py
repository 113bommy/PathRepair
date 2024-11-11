import re
i = input()
if re.fullmatch(r'(?:[a-z][A-Z]*)|(?:[A-Z]+)', i):
    i = i.swapcase()
print(i)