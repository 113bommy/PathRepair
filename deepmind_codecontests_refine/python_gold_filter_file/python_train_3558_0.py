n,m=map(int,input().split())
r=[0]
a=b=0
for i in range(n):
 c,d,k=int(input().replace(' ',''),2),0,3
 for j in range(m-1,0,-1):
  if a&c&k==k:r[0]+=1;r+=i,j;b|=k;d|=k
  k<<=1
 if a!=b:break
 a,b=c,d
print(*(r,[-1])[a!=b])