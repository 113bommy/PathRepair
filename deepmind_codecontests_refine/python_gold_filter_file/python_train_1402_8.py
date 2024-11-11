m,n=[int(x) for x in input().split()]
if n-m<=1:
    print(-1)
elif n-m==2:
    if m%2==0:
        print(m,m+1,n)
    else:
        print("-1")
else:
    if m%2==0:
        print(m,m+1,m+2)
    else:
        print(m+1,m+2,m+3)