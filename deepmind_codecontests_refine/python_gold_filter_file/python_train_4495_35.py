s=str(input())
s=s.lower()
v=['a','e','i','o','u','y']
for i in v:
    if i in s:
        s=s.replace(i,'')
c=''
for i in s:
    c+='.'+i
print(c)