s=input()
iss=0
no=0
for i in range(0,len(s)):
    if (s[i].isupper()):
        iss+=1
    else:
        no+=1
if iss>no:
    print(s.upper())
else:
    print(s.lower())