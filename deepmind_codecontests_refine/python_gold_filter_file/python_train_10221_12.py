q=list(map(int,input().split()))
import math
e=math.gcd(q[0],q[1])
n=q[0]//e
m=q[1]//e
for i in range(q[2]):
    w=list(map(int,input().split()))
    if w[0]==1 and w[2]==2:
        if (w[1]-1)//n==(w[3]-1)//m:
            print('YES')
        else:
            print('NO')
    elif w[0]==2 and w[2]==1:
        if (w[1]-1)//m==(w[3]-1)//n:
            print('YES')
        else:
            print('NO')
    elif w[0]==1 and w[2]==1:
        if (w[1]-1)//n==(w[3]-1)//n:
            print('YES')
        else:
            print('NO')
    elif w[0]==2 and w[2]==2:
        if (w[1]-1)//m==(w[3]-1)//m:
            print('YES')
        else:
            print('NO')