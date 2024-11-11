x=input()
z=x.split( )
k2=int(z[0])
k3=int(z[1])
d=[int(z[2]),int(z[3])]
k=min(d)
s=0
if k>k2:
    s+=(k2*256)
    k2=0
elif k==k2:
    s+=(k2*256)
    k2=0
else:
    k2-=k
    s+=(k*256)
o=[k2,k3]
g=min(o)
s+=(g*32)
print(s)
    
    
    
