import re

r = r"(ogo(go)*)"
input()
s = input()

s = re.sub(r, '***', s)

print(s)
