import re
s = input()
m = re.findall(r"([ACGT]+)",s)
print(len(max(m,key=len)) if m else 0)