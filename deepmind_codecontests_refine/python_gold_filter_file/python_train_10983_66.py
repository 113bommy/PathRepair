a=list(map(chr,range(97,123)))
b=list(map(chr,range(65,91)))
c=0
d=0
s=input()
for i in s:
    if i in a:
        c+=1
    if i in b:
        d+=1
if(c>=d):
    print(s.lower())
else:
    print(s.upper())