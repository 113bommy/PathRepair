s=input()
A=s.index("A")
Z=s[::-1].index("Z")
print(len(s)-A-Z)