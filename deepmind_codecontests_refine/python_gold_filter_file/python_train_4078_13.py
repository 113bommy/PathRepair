w,h=map(int,input().split())
l=w+h
res=1
mod=998244353
for i in range(l):
    res=(res%mod)*2
print(res%mod)