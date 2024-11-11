mod=10**9+7
dic={}
def ADD(x):
	if x in dic:
		dic[x]+=1
	else:
		dic[x]=1
n,m=map(int,input().split())
for i in range(2,int(m**0.5+2)):
	while m%i==0:
		ADD(i)
		m//=i
if m>1:
	ADD(m)
dic=tuple(dic.values())
ans=1
fac=[1]
for i in range(10**6):
	fac.append(fac[-1]*(i+1)%mod)
def c(a,b):
	r=pow(fac[b]*fac[a-b]%mod,mod-2,mod)
	return fac[a]*r%mod
for x in dic:
	ans*=c(x+n-1,x)
	ans%=mod
print(ans)
