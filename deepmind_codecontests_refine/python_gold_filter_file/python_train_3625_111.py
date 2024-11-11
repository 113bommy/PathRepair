import re
s = input()
print("AC" if re.match(r'^A[a-z][a-z]*C[a-z]*[a-z]$',s) else "WA")