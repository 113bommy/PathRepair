s=input()
if s.isupper() :
    s=s.lower()
elif s[0].islower() and s[1:].isupper():
    s=s[0].upper()+s[1:].lower()
elif len(s)==1:
    s=s.upper()
print(s)
