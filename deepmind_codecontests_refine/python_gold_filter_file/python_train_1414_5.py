k,a,b=map(int,input().split())
ak=a//k
bk=b//k
if a%k<=bk*k and b%k<=ak*k: print(ak+bk)
else: print(-1)