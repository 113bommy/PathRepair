n,m=map(int,input().split())
f=sorted([int(x) for x in input().split()])
d=1000
for i in range(m-n+1):
   d=min(d,f[i+n-1]-f[i])
print(d)
         
