I=lambda:list(map(int,input().split()))
x,y,s=map(int,input().split())
d=abs(x)+abs(y)
if s<d:
    print('No')
elif d==s:
    print('Yes')
else:
    if (d-s)%2:
        print('No')
    else:
        print('Yes')