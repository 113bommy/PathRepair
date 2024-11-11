n= int(input())
a= set()#[k*(k+1)//2 for k in range(1,n)])
for i in range (n):
    x = i*(i+1)//2
    if x >=n:
        print('NO')
        break
    a.add(x)
    if n-x in a:
        print('YES')
        break
else :
    print('NO')