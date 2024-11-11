import re
s = str(input())
c=0
c1=0

for i in s:
        if(re.search("[A-Z]",i)):
                c+=1
        if(re.search("[a-z]",i)):
                c1+=1
if(c>c1):
        s = s.upper()
else:
        s = s.lower()
print(s)
