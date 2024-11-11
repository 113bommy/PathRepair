a,b=map(int,input().split())
x1=0
x2=0
for x1 in range(1,a):
    for x2 in range(1,b):
        i=(a*a-x1*x1)**0.5
        if int(i)==i:
            j=(b*b-x2*x2)**0.5
            if int(j)==j:
                if i!=j and (-x2-x1)**2+(i-j)**2==a*a+b*b:
                    print('YES')
                    print(0,0)
                    print(x1,int(i))
                    print(-x2,int(j))
                    exit(0)
print('NO')