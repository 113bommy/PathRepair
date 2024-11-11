s=input()
l=u=0
for i in s:
    if i.islower():
        l=l+1
    else:
        u=u+1
if u<=l:
    print(s.lower())
else:
    print(s.upper())