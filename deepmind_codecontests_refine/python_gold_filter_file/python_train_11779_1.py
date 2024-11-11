a = list(map(int,input().split()))
x = list(map(int,input().split()))

if (-a[0]+x[0])>=0 and (-a[1]+(x[0]+x[1]-a[0]))>=0 and (-a[2]+(sum(x)-a[0]-a[1]))>=0:
    print("YES")
else:
    print('NO')