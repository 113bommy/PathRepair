import re
S = input()
c = r"A[a-z]+C[a-z]+$"
print("AC" if re.match(c,S) else "WA")

