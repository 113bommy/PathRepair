z=lambda :list(map(int,input().split()))
x=z()
y=z()
s=0
for i in range(3):
    k=x[i]-y[i]
    if k<0:s+=k
    else:s+=k//2
if s<0:print("No")
else:print("Yes")