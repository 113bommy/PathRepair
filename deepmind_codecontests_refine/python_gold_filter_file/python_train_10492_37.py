import re
s=input()
if re.fullmatch(r'(hi)+',s):
    print("Yes")
else:
    print("No")