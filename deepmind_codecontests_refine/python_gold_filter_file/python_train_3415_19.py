n,l=map(int,input().split( ))

s=n*(2*l+n-1)//2

if l>0:
    s-=l
elif l==0:
    pass
elif l+n<=0:
    s-=l+n-1

print(s)