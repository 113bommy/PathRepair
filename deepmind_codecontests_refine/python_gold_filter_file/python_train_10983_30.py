n=str(input())
c=[]
s=[]
for i in n:
    if i.isupper():
        c.append(i)
    else:
        s.append(i)
if len(c)>len(s):
    print(n.upper())
else:
    print(n.lower())