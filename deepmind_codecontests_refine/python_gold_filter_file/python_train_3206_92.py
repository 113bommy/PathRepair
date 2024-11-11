a,b,c = map(int,input().split())

if c<a:
    print(a-c,b)
else:
    print(0,max(b+a-c,0))
