s=input()
l=0
u=0
for i in s:
   if i.isupper():
      u+=1
   else:
      l+=1
if l>=u:
   s=s.lower()
else:
   s=s.upper()
print(s)
