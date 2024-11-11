x,y,z,t1,t2,t3=list(map(int,input().split()))
if abs(x-y)*t1>=(abs(x-y)+abs(x-z))*t2+3*t3:
    print('YES')
else:
    print('NO')