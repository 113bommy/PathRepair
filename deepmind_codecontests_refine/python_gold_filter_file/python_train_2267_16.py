x,n,*a=map(int,open(0).read().split())
b=[1]*103
for i in a:
    b[i]=0
c=1000 
ans=n
for i in range(102):
    if b[i] and c>abs(x-i):
        c=abs(x-i)
        ans=i
print(ans)