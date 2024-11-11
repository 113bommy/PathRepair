s=['H','Q','9']
a=input()
x=[]
for i in range(len(a)):
    if a[i] in s:
        x.append(1)
    else:
        x.append(0)
if sum(x)>0:
    print('YES')
else:
    print('NO')
