n=int(input())
nn=n
nnn=n
a=[]
x=1
while nn>0:
    a.append(x)
    nn=nn-1
x=0
y=0
z=0
while nnn<n*n:
    z=z+int(a[x])
    a.append(str(z))
    x=x+1
    if x==nnn:
        nnn=nnn+n
        z=0
print(a[-1])
        
