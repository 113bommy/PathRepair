a,b=map(int,input().split())
x=[int(i) for i in input().split()]
if sum(x)-max(x)<=b:
    print('YES')
else:
    print('NO')
