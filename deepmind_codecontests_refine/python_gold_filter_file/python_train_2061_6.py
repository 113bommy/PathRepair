s=input()
a=list(s[1::2])
b=list(s[0::2])
if "R" in a or "L" in b:
    print("No")
else:
    print("Yes")