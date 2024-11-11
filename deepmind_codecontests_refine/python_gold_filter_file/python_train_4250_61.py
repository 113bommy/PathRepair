a,b,c=map(int,input().split())
k=[]
for i in range(1,101):
  if a%i==0 and b%i==0:
    k.append(i)
print(k[-c])