# Why do we fall ? So we can learn to pick ourselves up.
import re
ss = input().strip()
s = re.findall("[\w']+|[.,!?]",ss)
ans = ""
for i in s:
    if i == ',' or i == '?' or i == '!' or i == '.':
        ans = ans.strip()
        ans += i+" "
    else:
        ans += i+" "
print(ans.strip())

