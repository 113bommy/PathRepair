s=input()
v= "aouie"
b=''
for i in s:
    if i in v:
        b+='0'
    elif i == 'n':
        b+='2'
    else:
        b+='1'
if '11' in b or '12' in b or s[-1] not in v+'n':
    print('NO')
else:
    print('YES')