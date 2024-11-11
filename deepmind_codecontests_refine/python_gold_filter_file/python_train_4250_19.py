a,b,k=map(int,input().split())
l=[]
for i in range(min([a,b])+1,0,-1):
  if a%i==0 and b%i==0:
    l.append(i)
print(l[k-1])