def p(x):
    if  x==2:
        return 1
    else:
        c=0
        for i in range(2,x):
            if x%i==0:
                c+=1
        if c>0:
            return 0
        else:
            return 1

x=input().split()
n=int(x[0])
m=int(x[1])
if (m-n)%2==0 or n==2:
 for j in range(n+1,m+1):
    if n==2:
        if m==3:
            print('YES')
            break
        else:
            print('NO')
            break
    elif n>2:
        a=p(j)
        if a==1:
            if j<m:
                print('NO')
                break
            else:
                print('YES')
                break
        elif a==0:
            if j==m:
                print('NO')
                break
else:
    print('NO')