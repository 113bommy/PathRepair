import re

s = input()

if re.search(".*h.*e.*l.*l.*o", s):
    print("YES")
else:
    print("NO")