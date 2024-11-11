for _ in " "*int(input()):
    a,b=map(int,input().split())
    z=list(map(int,input().split()))
    k=set(z)
    if len(k)>b:print(-1);continue
    print(a*b)
    k=list(k)+[1]*(b-len(k))
    print(*k*a)