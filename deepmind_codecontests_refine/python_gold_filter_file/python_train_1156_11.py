def tp(n):
    k=1
    while k<n:
        k*=2
    return k
n=int(input())
a=[]
z=1
if n==1:
    exit(print(1,0))
for i in range(2,int(n**.5)+1):
    r=0
    if n%i==0:
        z*=i
    while n%i==0:
        n//=i
        r+=1
    if r>0:
        a.append(r)
if n>1:
    a.append(1)
    z*=n
l=max(a)
k=tp(l)
mo=0
fl=0
for i in a:
    if i!=k:
        fl=1
        break
while k!=1:
    k//=2
    mo+=1
if fl:
    print(z,mo+1)
else:
    print(z,mo)



    