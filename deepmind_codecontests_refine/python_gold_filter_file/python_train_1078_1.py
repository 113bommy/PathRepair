n = int(input())
if n==1 or n==2:
    print("-1")
else:
    if n==3:
        print("210")
    else:
        n = n-1
        p = pow(10,n)
        print(p+210-p%210)