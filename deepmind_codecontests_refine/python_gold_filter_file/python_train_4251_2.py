import collections

def factor(m):
    num=m
    s=[]
    i=2
    while i*i<=m:
        if num%i:
            i+=1
        else:
            s.append(i)
            num//=i
    if num!=1:
        s.append(num)
    return s

def conb(n, r):
	N, R = n, r
	for i in range(1, r):
		N *= n-i
		R *= r-i
	return N // R
	
n,m=map(int,input().split())
a=factor(m)
b=collections.Counter(a)
mod=10**9+7
ans=1
for i in b.values():
    ans=(ans*conb(n+i-1,i))%mod
print(ans)