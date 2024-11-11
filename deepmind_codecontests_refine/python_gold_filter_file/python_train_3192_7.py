import re
f=re.search
x=input()
s=input()

if f('CC|MM|YY',s) or not f(r'^\?|\?\?|\?$|(C|M|Y)\?\1',s):
    print("NO")
else:
    print("YES")
