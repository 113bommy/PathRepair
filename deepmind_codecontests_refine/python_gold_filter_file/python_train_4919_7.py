n,s=map(int,input().split())
if(n==s):
    print("NO")
elif(n==1 and s>1):
    print("YES")
    print(s)
    print(1)
else:
    a=1
    b=s-n+1
    l=[1]*(n-1)
    l.append(b)
    if(b-a==1):
        print("NO")
    else:
        if(b>n-1 and b!=n):
            print("YES")
            print(*l)
            print(n)
        else:print('NO')