n,k=input().split(' ')
n=int(n)
k=int(k)
r=n*2
g=n*5
b=n*8
if r%k==0:
    rb=r/k
else:
    rb=(r//k)+1
if g%k==0:
    gb=g/k
else:
    gb=(g//k)+1
if b%k==0:
    bb=b/k
else:
    bb=(b//k)+1
sum=rb+gb+bb
print("%d" %(sum))
