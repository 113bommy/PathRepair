n,m=map(int,input().split())
res=-1
if m%n==0:
    res=0
    d=m//n
    while(d%2==0):
        d//=2
        res+=1
    while d%3==0:
        d//=3
        res+=1
    if d!=1:
        res=-1
print(res)