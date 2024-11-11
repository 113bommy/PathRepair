a=input()

b=set('HQ9')-set(a)

if(len(b)<3):
    print('YES')
else:
    print('NO')