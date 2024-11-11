import math
n,m,k=map(int,input().split())
for i in range(1,n+1):
    if k<=2*i*m:break
k=k-(2*(i-1)*m)
j=math.ceil(k/2)
print(i,j,['L','R'][k%2==0])