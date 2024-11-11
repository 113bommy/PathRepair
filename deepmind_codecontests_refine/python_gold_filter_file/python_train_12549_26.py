b = int(input())
a = [int(i) for i in input().split()]
k=0
if b==1:
    if a[0]==0:
        print('NO')
    else:
        print('YES')
else:
    for i in a:
        if i==0:
            k+=1
    if k==1:
        print('YES')
    else:
        print('NO')

        