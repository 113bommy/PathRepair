import re
ans = max(map(len, re.findall("[ACGT]*", input())))
print(ans)