str= input()
dash=0
ows=0
for a in str:
    if a=='-':
        dash+=1
    if a=='o':
        ows+=1
try:
    if dash%ows==0:
        print('YES')
    else:
        print('NO')
except:
    print('YES')
