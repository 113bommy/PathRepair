s=input()
v='aeiouy'
c='bcdfghjklmnpqrstvwxz'
j=-1
for i in range(-1,-len(s)-1,-1):
    c=s[i]
    if c!="?" and c!=" ":
        j=i
        break
char=s[j].lower()
if char in v:
    print("YES")
elif char in c:
    print("NO")
else:
    print("NO")