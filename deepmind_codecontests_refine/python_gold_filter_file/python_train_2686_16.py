p=int(input())
a=[int(i) for i in input().split()]
b=[0 for i in range(p)]
#f(i)=ai
#(i,ai) 0<=i<p
#P(x)=sum range(p+1) ai fi(x)/fi(i)
#fi(i)=i!*(N-i-1)!
c=[0 for i in range(p+1)]
c[1]=-1
c[-1]=1
def inv(x):
    return pow(x,p-2,p)
def divide(k):
    #cを(x-k)で割る
    tmp=[c[i] for i in range(p+1)]
    res=[0 for i in range(p)]
    for i in range(p-1,-1,-1):
        res[i]=tmp[i+1]
        tmp[i]+=k*tmp[i+1]
        tmp[i]%=p
        #print(k,tmp,res)
    return res
#devide(i):fi(x)
Fact=[0 for i in range(p)]
Finv=[0 for i in range(p)]
Fact[0]=1
for i in range(p-1):
    Fact[i+1]=((i+1)*Fact[i])%p
Finv[p-1]=inv(Fact[p-1])
for i in range(p-1)[::-1]:
    Finv[i]=((i+1)*Finv[i+1])%p
ans=[0 for i in range(p)]
for i in range(p):
    fix=divide(i)
    fixiinv=(Finv[i]*Finv[p-i-1])%p
    fixiinv*=(-1)**(p-i-1)
    fixiinv%=p
    #print(fix,a[i],fixiinv)
    for j in range(p):
        ans[j]+=(((a[i]*fix[j])%p)*fixiinv)%p
        ans[j]%=p
print(*ans)
