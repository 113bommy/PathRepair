n,m=map(int,input().split())
d=(n*(n-1))//2
d1=(n-1)//2
d1=d1*(d1+1)+(1-n%2)*n//2
#print(d,d1)
s=0
for i in range(m):
    x,y=map(int,input().split())
    s+=n*x
    if y>0:
        s+=d*y
    else:
        s+=d1*y
print(s/n)
    
    