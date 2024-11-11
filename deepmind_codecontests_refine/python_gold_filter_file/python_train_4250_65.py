a,b,k=map(int,input().split())
d=[]
for i in range(1,101): 
  if a%i==0 and b%i==0:
    d.append(i)

print(d[-k])