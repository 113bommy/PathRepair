a=input()
b=input()
c=input()
letters=[0]*26
letters1=[0]*26
for i in c.lower():
    if i >= 'a' and i<='z':
        nomer = ord(i) - 97
        letters[nomer]+=1
for i in (a+b).lower():
    if i >= 'a' and i<='z':
        nomer = ord(i) - 97
        letters1[nomer]+=1
if letters==letters1:
    print('YES')
else:
    print('NO')