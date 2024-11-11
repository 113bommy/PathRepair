s = str(input())
c1 = c2 = 0
for i in s:
    if i>='a' and i<='z':
        c1+=1
    if i>='A' and i<='Z':
        c2+=1

if c1>=c2:
    print(s.lower())
else:
    print(s.upper())