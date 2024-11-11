n,s=map(int,input().split())
if n==1 and s==1:
    print("NO")
else:
    b=[1 for i in range (n-1)]
    c=sum(b)
    b.append(s-n+1)
    if c+1 <b[-1]:
        print("YES")
        print(*b)
        print(c+1)
    else:
        print("NO")