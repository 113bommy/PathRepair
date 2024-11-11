import re

txt = input()
z = re.match("^A[a-z]+C[a-z]+$", txt)

print("AC" if z else "WA")