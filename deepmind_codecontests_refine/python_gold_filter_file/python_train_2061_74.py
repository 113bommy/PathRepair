s=input()
a=s[1::2]
b=s[::2]
if ("L" not in b) and ("R" not in a):print("Yes")
else:print("No")
