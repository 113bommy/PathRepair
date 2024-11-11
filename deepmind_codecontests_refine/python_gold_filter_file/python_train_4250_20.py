a,b,k=map(int,input().split())
d=[]
for i in range(1,101):
  if(a%i==0 and b%i==0):
    d.append(i)
e=d[::-1]
print(int(e[k-1]))