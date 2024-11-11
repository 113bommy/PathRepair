n,m = map(int,input().split())
mas = list(map(int,input().split()))
res,q = 0,1
for i in range(n-1):
    if mas[i]!=mas[i+1]:
        q+=1
    else:
        if q>res:
            res=q
        q=1
if res<q:
    res=q
print(res)