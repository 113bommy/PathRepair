import math
t=int(input())
for k1 in range(t):
    a, b=map(int, input().rstrip().split())
    condition=True
    if (a-b)==1:
        c=(a+b)
        if c==2 or c==3:
            print('YES')
        if c!=2 and c!=3:
            for i in range(2, math.floor(math.sqrt(c))+1):
                if c%i==0:
                    condition=False
                    break
            if condition:
                print('YES')
            if not condition:
                print('NO')
    if (a-b)!=1:
        print('NO')