import re
ans=re.match("A[a-z]+C[a-z]+$",input())
print("AC" if ans else "WA")