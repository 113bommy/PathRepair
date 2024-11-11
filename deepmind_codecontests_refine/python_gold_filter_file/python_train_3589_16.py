I=lambda:list(map(int,input().split()))
n,m=I()
a=I()[1::]
b=I()[1::]
ans=[0]*max(n,m)
bo=[0]*n
gl=[0]*m
for i in a:
    bo[i-1]=1
for j in b:
    gl[j-1]=1
boy=set()
girl=set()
for i in range(n*m+n*m):
    x=bo[i%n]
    y=gl[i%m]
    if x|y:
         bo[i%n]=1
         gl[i%m]=1
if bo.count(1)+gl.count(1)==n+m:
    print('Yes')
else:
    print('No')
