s=input()
u,l=0,0
for i in s:
    if i<='z' and i>='a': l+=1
    else:
        u+=1
if (l<u):
    print(s.upper())
else:
    print(s.lower())