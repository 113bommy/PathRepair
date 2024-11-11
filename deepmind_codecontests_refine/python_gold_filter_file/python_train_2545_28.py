a,b,c,d = map(int,input().split())
if a!=c and b!=d and abs(a-c)!=abs(b-d):
    print(-1)
else:
    if a==c:
        print(a+abs(b-d),b,c+abs(b-d),d)
    elif b==d:
        print(a,b+abs(a-c),c,d+abs(a-c))
    else:
        print(a,d,c,b)