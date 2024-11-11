s=input()
c=0
j=0
for i in s:
    if i.isupper():
        c=c+1
    if i.islower():
        j=j+1
if c<=j:
    k=s.lower()
    print(k)
else:
    k=s.upper()
    print(k)