s = str(input())
if "R" not in s[1::2] and "L" not in s[0::2]:
    print("Yes")
else:
    print("No")