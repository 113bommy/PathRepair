n,m,b = map(int,input().split())
l = list(map(int,input().split()))
h = list(map(int,input().split()))
c = b-(min(l)*(b//min(l)))+(max(h)*(b//min(l)))
if c>b:
    print(c)
else:
    print(b)
    
