# A. word
a = input()
nl = 0
nu = 0
for i in a:
    if i.islower():
        nl+=1
    else:
        nu+=1
if nl>=nu:
    print(a.lower())
else:
    print(a.upper())