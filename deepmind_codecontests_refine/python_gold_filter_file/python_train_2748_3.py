I=input
n,m=map(int,I().split())
b=[1]*n*2
b[0]=b[n-1]=b[n]=b[2*n-1]=0
for i in range(m):
    r,c=map(int,I().split())
    b[r-1]=b[n+c-1]=0
if n%2 and b[n//2] and b[n+n//2]:b[n//2]=0
print(sum(b))