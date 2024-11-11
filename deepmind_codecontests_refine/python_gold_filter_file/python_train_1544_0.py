def E(i,y):
    if i==1:
        return 5*y
    else:
        return (2*i+1)*y

def ceil(a,b):
    return -((-a)//b)
N,X=map(int,input().split())
x=[int(i) for i in input().split()]
a=[0]
for i in range(N):
    a.append(a[-1]+x[i])
ans=10**50
for k in range(1,N+1):
    tmp=(N+k)*X
    for i in range(N//k):
        tmp+=E(i+1,a[N-i*k]-a[N-i*k-k])
        #print(k,i,tmp)
    if N%k!=0:
        tmp+=E(N//k+1,a[N-(N//k)*k])
    #print(tmp)
    if ans>tmp:
        ans=tmp
print(ans)
