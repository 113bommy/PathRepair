import re
n=input()
print("YES" if re.search('^(1|14|144)+$',n) else "NO")