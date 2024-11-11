import re
print(max(map(len, re.findall("A.*Z", input()))))
