t=int(input())
for i in range(t):
    n,k=input().split()
    n,k=int(n),int(k)
    a=input().split()
    b=set(a)
    if len(b)>k:
        print(-1)
    else:
        x=list(b)
        for j in range(k-len(b)):
            x.append(1)
        x=x*n
        print(len(x))
        print(*x)