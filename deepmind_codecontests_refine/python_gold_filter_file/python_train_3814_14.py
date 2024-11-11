n=int(input())
a=[int(i) for i in input().split()]
b=[31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31]
flag=0
for i in range(0,48):
    if b[i:n+i]==a:
        flag=1
        break
    elif b[i:]+b[:(n+i)%48]==a:
        flag=1
        break
if flag==0:
    print('NO')
else:
    print('YES')
