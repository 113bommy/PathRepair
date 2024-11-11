a,b,c,d=map(int,input().split())
m=max(c,d)
if(2*c>=m and 2*d>=m and m<b):
    print(2*a,2*b,m)
else:
    print(-1)
