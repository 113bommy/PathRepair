from math import factorial

N,M = map(int,input().split())

pdic={}

p=2
while p**2<=M:
    c=0
    while M%p==0:
        c+=1
        M//=p
    if c>0:
        pdic[p]=c
    p+=1
if M>1:
    pdic[M]=1

ans=1
tmp=factorial(N-1)

for p in pdic.keys():
    e=pdic[p]
    ans*=factorial(N+e-1)//(factorial(e)*tmp)

print(ans%(10**9+7))
