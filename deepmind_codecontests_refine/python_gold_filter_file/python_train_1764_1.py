while 1:
    n=int(input())
    if n==0:break
    x=y=10
    b=[list(map(int,input().split())) for _ in range(n)]
    for i,j in [input().split() for _ in range(int(input()))]:
        for _ in range(int(j)):
            if 'N'<=i<='S': y+=1 if i=='N' else -1
            else: x+=1 if i=='E' else -1
            if [x,y] in b:del b[b.index([x,y])]
    print(['Yes','No'][bool(b)])