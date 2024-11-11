x=input()
if x.count('o')!=0:
    print('YES' if x.count('-')%x.count('o')==0 else 'NO')
else:
    print('YES')