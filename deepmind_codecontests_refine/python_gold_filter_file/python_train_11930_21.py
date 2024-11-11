n,t,k,d=[int(x) for x in input().split() ]
x=(int(d/t)+1)
x=x*k
rest=n-x
if rest >= 1:
    print('YES')
else:
    print('NO')