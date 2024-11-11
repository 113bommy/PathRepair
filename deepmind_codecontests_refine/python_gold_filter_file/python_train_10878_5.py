c=[0]*1000001
n=int(input())
mi=ma=k=0
for i in range(n):
   a,b=input().split()
   b=int(b)
   if a=="+": k+=1; c[b]=1
   else: 
      if c[b]: k-=1; c[b]=0
      else: ma+=1
   ma=max(ma,k)
   mi=min(mi,k)
print(ma-mi)
