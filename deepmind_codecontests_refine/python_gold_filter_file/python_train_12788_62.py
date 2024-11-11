a,b,c,d,e,f=map(int,input().split())
x=set()
y=set()
m=f//(100*a)
for i in range(m+1):
  for j in range(f//(100*b)+1):
    x1=i*100*a+j*100*b
    if x1<=f:
      x.add(x1)

m=int(f*(e/100))
for i in range(0,m+1,c):
  for j in range(0,m-i+1,d):
     y.add(i+j)
x.remove(0) 
z=[-1]
ans=[]
for i in x:
  for j in y:
    if i+j<=f and j*100/(i+j)<=e*100/(100+e):
      if j*100/(i+j)>max(z):
        z.append(j*100/(i+j))
        ans.append([i+j,j])
        
print(ans[-1][0],ans[-1][1])
