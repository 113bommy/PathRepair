a,b,k=map(int,input().split())
p=[]
for i in range(1,a+1):
  if a%i==0 and b%i==0:
    p.append(i)

n=len(p)
print(p[n-k])