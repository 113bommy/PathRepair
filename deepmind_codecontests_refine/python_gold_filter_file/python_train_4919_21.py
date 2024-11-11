n,s=map(int,input().split())
if(n==1 and s==1):
    print("NO")
elif(2*(n)>s):
    print('NO')
else:
    l=[]
    cs=0
    for i in range(n-1):
        l.append(2)
        cs+=2
    ls=s-cs
    l.append(ls)
    print("YES")
    print(*l)
    print(1)

