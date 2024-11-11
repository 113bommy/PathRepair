import re

s = input()
l = re.findall('[ACGT]*', s)
print(len(max(l,key=len)))