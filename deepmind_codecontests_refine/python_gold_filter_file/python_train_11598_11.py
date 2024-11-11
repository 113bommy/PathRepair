import re
a=input()
print("YES" if re.search('^(1|14|144)+$',a) else "NO")